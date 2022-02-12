static int SetBlobCmp(const void *elem1, const void *elem2)
{
const MYBLOB *b1 = (const MYBLOB *)elem1;
const MYBLOB *b2 = (const MYBLOB *)elem2;
int r;
r = memcmp(b1->pbData, b2->pbData,
b1->cbData < b2->cbData ? b1->cbData : b2->cbData);
if (r != 0)
return r;
return b1->cbData - b2->cbData;
}
