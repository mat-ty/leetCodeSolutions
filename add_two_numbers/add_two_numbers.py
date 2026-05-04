# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        remainder = 0
        l3 = ListNode(0, None)
        sent = l3
        sub = ListNode(0,None)

        while (l1 or l2):
            # l3.next = ListNode(0, None) if ((not l1 or l1.next) or (not l2 or l2.next)) else None
            l1v = l1.val if l1 else 0
            l2v = l2.val if l2 else 0

            s = l1v + l2v + remainder
            remainder = int(s/10) 
            l3.val = s%10


            l1 = l1.next if l1 else 0
            l2 = l2.next if l2 else 0
            l3.next = ListNode(0, None) if (l1 or l2) else None
            if (l1 or l2):
                l3.next = ListNode(0, None)
            elif remainder:
                l3.next = ListNode(remainder, None)
            else:
                l3.next = None
            # print(l1,"|||",l2,"|||",l3)
            l3 = l3.next

        # if(remainder>0):
        #     # print("here", remainder, l3)
        #     l3.val = remainder
   


        return sent   

