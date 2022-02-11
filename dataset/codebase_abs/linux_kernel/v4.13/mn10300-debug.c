void F_1 ( const char * V_1 , int V_2 )
{
char V_3 ;
for (; V_2 > 0 ; V_2 -- ) {
V_3 = * V_1 ++ ;
#if V_4 == 0
while ( V_5 & ( V_6 ) ) continue;
V_7 = V_3 ;
while ( V_5 & ( V_6 ) ) continue;
if ( V_3 == 0x0a ) {
V_7 = 0x0d ;
while ( V_5 & ( V_6 ) ) continue;
}
#elif V_4 == 1
while ( V_8 & ( V_6 ) ) continue;
V_9 = V_3 ;
while ( V_8 & ( V_6 ) ) continue;
if ( V_3 == 0x0a ) {
V_9 = 0x0d ;
while ( V_8 & ( V_6 ) ) continue;
}
#elif V_4 == 2
while ( V_10 & ( V_11 ) ) continue;
V_12 = V_3 ;
while ( V_10 & ( V_11 ) ) continue;
if ( V_3 == 0x0a ) {
V_12 = 0x0d ;
while ( V_10 & ( V_11 ) ) continue;
}
#endif
}
}
