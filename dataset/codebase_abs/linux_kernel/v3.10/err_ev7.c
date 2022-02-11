struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_2 * V_5 ;
int V_6 ;
if ( V_3 -> V_7 != V_8 ||
V_3 -> type != V_9 )
return NULL ;
V_3 = (struct V_2 * )
( ( unsigned long ) V_3 + V_3 -> V_10 ) ;
if ( V_3 -> V_7 != V_11 ||
V_3 -> type != V_12 )
return NULL ;
V_4 -> V_13 = (struct V_14 * )
V_3 -> V_15 . V_16 . V_17 ;
V_5 = (struct V_2 * )
( ( unsigned long ) V_3 + V_3 -> V_10 ) ;
for ( V_6 = 0 ;
V_5 && V_6 < V_4 -> V_13 -> V_18 ;
V_5 = (struct V_2 * )
( ( unsigned long ) V_5 + V_5 -> V_10 ) , V_6 ++ ) {
if ( V_5 -> V_7 != V_11 ) {
F_2 ( L_1
L_2 ,
V_19 , V_5 -> V_7 , V_6 ) ;
return NULL ;
}
switch( V_5 -> type ) {
case V_20 :
V_4 -> V_21 =
(struct V_22 * )
V_5 -> V_15 . V_16 . V_17 ;
break;
case V_23 :
V_4 -> V_24 = (struct V_25 * )
V_5 -> V_15 . V_16 . V_17 ;
break;
case V_26 :
V_4 -> V_27 = (struct V_28 * )
V_5 -> V_15 . V_16 . V_17 ;
break;
case V_29 :
V_4 -> V_30 = (struct V_31 * )
V_5 -> V_15 . V_16 . V_17 ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_4 -> V_39 [ F_3 ( V_5 -> type ) ] =
(struct V_40 * )
V_5 -> V_15 . V_16 . V_17 ;
break;
default:
return NULL ;
}
}
return V_4 ;
}
void
F_4 ( unsigned long V_41 , unsigned long V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 ;
char * V_43 = V_19 ;
F_5 () ;
F_6 () ;
V_19 = V_44 ;
F_2 ( L_3 ,
V_19 ,
( V_41 == V_45 ) ? L_4 : L_5 ,
( unsigned int ) V_41 , ( int ) F_7 () ) ;
F_8 ( V_3 ) ;
V_19 = V_43 ;
F_9 ( 0x7 ) ;
F_5 () ;
}
static struct V_2 *
F_10 ( struct V_2 * V_46 )
{
struct V_47 * V_48 ;
if ( V_46 -> V_7 != V_11 ) {
F_2 ( L_6 ,
V_19 ,
V_46 -> V_7 , V_46 -> type ) ;
return NULL ;
}
V_48 = (struct V_47 * ) V_46 -> V_15 . V_16 . V_17 ;
switch( V_46 -> type ) {
case V_12 :
F_2 ( L_7 ,
V_19 ,
V_48 -> V_15 . V_13 . V_49 ,
V_48 -> V_15 . V_13 . V_50 ) ;
F_11 ( & V_48 -> V_15 . V_13 . V_51 ) ;
F_2 ( L_8
L_9 ,
V_19 ,
V_48 -> V_15 . V_13 . V_52 ,
V_48 -> V_15 . V_13 . V_53 ) ;
F_12 ( V_46 ,
V_48 -> V_15 . V_13 . V_18 ) ;
break;
default:
F_2 ( L_10 ,
V_19 ,
V_46 -> type ) ;
F_13 ( V_46 ) ;
break;
}
return (struct V_2 * ) ( ( unsigned long ) V_46 + V_46 -> V_10 ) ;
}
void T_1
F_14 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_15 ( V_54 ) ; V_6 ++ )
F_16 ( & V_54 [ V_6 ] ) ;
F_17 ( & V_55 ) ;
}
