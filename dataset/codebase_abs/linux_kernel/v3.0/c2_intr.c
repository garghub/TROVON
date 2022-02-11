void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
while ( V_2 -> V_4 != F_2 ( * V_2 -> V_5 ) ) {
V_3 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_3 & 0x80000000 ) {
break;
}
V_2 -> V_4 ++ ;
F_4 ( V_2 , V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_8 [ V_3 ] == NULL ) {
F_5 ( L_1 ,
V_3 ) ;
return;
}
switch ( V_3 ) {
case ( 0 ) :
F_6 ( & V_2 -> V_9 ) ;
break;
case ( 1 ) :
F_7 ( V_2 , V_3 ) ;
break;
case ( 2 ) :
F_7 ( V_2 , 1 ) ;
F_8 ( V_2 , V_3 ) ;
break;
default:
F_9 ( V_2 , V_3 ) ;
break;
}
return;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
void * V_10 , * V_11 ;
struct V_12 * V_13 ;
struct V_12 V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 V_20 ;
int V_21 ;
V_16 = (struct V_15 * ) V_2 -> V_8 [ V_3 ] ;
V_10 = F_10 ( V_16 ) ;
if ( V_10 == NULL ) {
return;
}
V_13 = F_11 ( V_2 ) ;
if ( ! V_13 ) {
F_5 ( L_2 ) ;
V_13 = & V_14 ;
memcpy ( V_13 , V_10 , sizeof( V_14 ) ) ;
V_11 = NULL ;
} else {
memcpy ( V_13 , V_10 , V_16 -> V_22 ) ;
V_11 = V_13 ;
}
F_12 ( V_16 ) ;
V_18 = (struct V_17 * ) ( unsigned long ) V_13 -> V_23 ;
if ( V_18 == NULL ) {
F_13 ( V_2 , V_13 ) ;
F_5 ( L_3 ) ;
return;
}
if ( V_11 )
V_21 = F_14 ( V_11 ) ;
else
V_21 = - V_24 ;
if ( ! V_21 ) switch ( V_18 -> V_25 ) {
case V_26 :
F_15 ( V_18 -> V_27 ,
V_28 ) ;
case V_29 :
V_20 . V_25 = V_18 -> V_25 ;
V_20 . V_30 = 0 ;
V_20 . V_31 = V_18 -> V_32 -> V_31 ;
V_20 . V_33 = V_18 -> V_32 -> V_33 ;
V_20 . V_34 = NULL ;
V_20 . V_35 = 0 ;
V_18 -> V_32 -> V_36 ( V_18 -> V_32 , & V_20 ) ;
break;
default:
break;
}
V_18 -> V_11 = ( V_37 ) ( unsigned long ) ( V_11 ) ;
F_16 ( & V_18 -> V_38 , 1 ) ;
F_6 ( & V_18 -> V_39 ) ;
F_17 ( V_2 , V_18 ) ;
}
