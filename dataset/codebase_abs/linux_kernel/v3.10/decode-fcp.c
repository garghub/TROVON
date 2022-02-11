static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 -> V_6 . V_7 . V_8 ;
const struct V_9 * V_10 ;
const char * V_11 ;
char V_12 [ 32 ] ;
int V_13 ;
V_10 = & V_14 [ V_4 -> V_15 ] ;
if ( V_10 -> V_11 == NULL ) {
snprintf ( V_12 , sizeof( V_12 ) ,
L_1 , V_4 -> V_15 ) ;
V_11 = V_12 ;
} else {
V_11 = V_10 -> V_11 ;
}
printf ( L_2 ,
V_16 [ V_4 -> V_17 ] , V_18 [ V_4 -> V_19 ] ,
V_4 -> V_20 , V_11 ) ;
for ( V_13 = 0 ; V_10 -> V_21 [ V_13 ] . V_11 != NULL ; V_13 ++ )
printf ( L_3 , V_10 -> V_21 [ V_13 ] . V_11 ) ;
printf ( L_4 ) ;
}
int
F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 -> V_6 . V_7 . V_8 ;
unsigned long long V_22 =
( ( unsigned long long ) V_2 -> V_5 -> V_6 . V_23 . V_24 << 32 ) |
V_2 -> V_5 -> V_6 . V_23 . V_25 ;
if ( V_2 -> V_5 -> V_6 . V_23 . V_26 != V_27 )
return 0 ;
if ( V_22 == V_28 || V_22 == V_29 ) {
switch ( V_4 -> V_30 ) {
case 0x00 :
F_1 ( V_2 ) ;
break;
case 0x01 :
printf ( L_5 ) ;
break;
case 0x02 :
printf ( L_6 ) ;
break;
case 0x03 :
printf ( L_7 ) ;
break;
case 0x0e :
printf ( L_8 ) ;
break;
case 0x0f :
printf ( L_9 ) ;
break;
default:
printf ( L_10 , V_4 -> V_30 ) ;
break;
}
return 1 ;
}
return 0 ;
}
