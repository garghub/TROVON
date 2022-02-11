static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 {
T_1 V_5 ;
T_1 V_6 ;
T_1 V_7 ;
};
struct V_8 {
T_1 V_5 ;
T_1 V_7 ;
};
struct V_9 {
struct V_8 V_10 ;
struct V_4 V_11 ;
unsigned int V_12 ;
};
const struct V_9 * V_13 ;
unsigned long V_11 ;
unsigned int V_10 ;
unsigned int V_12 ;
int V_14 = 0 ;
V_13 = F_2 ( V_2 , L_1 , & V_14 ) ;
if ( V_13 == NULL || ( V_14 < sizeof( struct V_9 ) ) )
goto V_15;
if ( ( V_13 -> V_10 . V_5 & V_16 ) != V_17 ) {
V_13 ++ ;
V_14 -= sizeof( struct V_9 ) ;
if ( V_14 < sizeof( struct V_9 ) )
goto V_15;
}
if ( ( V_13 -> V_10 . V_5 & V_16 ) != V_17 )
goto V_15;
V_10 = V_13 -> V_10 . V_7 ;
V_11 = ( unsigned long ) V_13 -> V_11 . V_6 << 32 |
V_13 -> V_11 . V_7 ;
if ( ( V_11 != 0 ) || ( V_10 != 0 ) ) {
F_3 ( V_18 L_2 ,
V_19 ) ;
return;
}
V_12 = F_4 ( V_13 -> V_12 ) ;
if ( V_12 > 0x10000 )
V_12 = 0x10000 ;
F_5 ( V_3 , ( void * ) V_20 ,
V_12 , F_6 ( F_7 ( F_8 ( 0 ) ) ) ) ;
return;
V_15:
F_3 ( V_18 L_3
L_4 ) ;
F_5 ( V_3 , ( void * ) V_20 ,
0x10000 , F_6 ( F_7 ( F_8 ( 0 ) ) ) ) ;
}
void T_2 F_9 ( struct V_21 * V_22 )
{
struct V_1 * V_23 , * V_24 = NULL , * V_25 ;
if ( V_26 != NULL )
return;
F_10 (np, L_5 ) {
for ( V_24 = F_11 ( V_23 ) ; V_24 ; ) {
if ( V_24 == V_22 -> V_27 ) {
F_12 ( V_24 ) ;
break;
}
V_25 = V_24 ;
V_24 = F_11 ( V_24 ) ;
F_12 ( V_25 ) ;
}
if ( V_24 != NULL )
break;
}
if ( V_23 == NULL )
return;
V_26 = V_23 ;
F_1 ( V_23 , V_22 -> V_28 ) ;
V_29 = V_20 ;
F_13 ( L_6 , V_23 -> V_30 ) ;
}
static void F_14 ( struct V_31 * V_32 ,
struct V_1 * V_33 )
{
struct V_21 * V_22 = F_15 ( V_32 -> V_34 ) ;
V_26 = F_16 ( V_33 ) ;
V_35 = V_32 ;
F_1 ( V_33 , V_22 -> V_28 ) ;
V_29 = V_20 ;
F_13 ( L_7 ,
V_33 -> V_30 , F_17 ( V_32 ) ) ;
}
static void F_18 ( void )
{
F_13 ( L_8 ) ;
V_29 = V_20 ;
F_12 ( V_26 ) ;
V_26 = NULL ;
V_35 = NULL ;
F_19 ( ( void * ) V_20 , 0x10000 ) ;
}
static int F_20 ( struct V_36 * V_37 , unsigned long V_38 ,
void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_31 * V_32 = F_21 ( V_41 ) ;
struct V_1 * V_33 = F_22 ( V_32 ) ;
switch( V_38 ) {
case V_42 :
if ( V_26 && V_26 == V_33 &&
! V_35 ) {
F_13 ( L_9 ,
F_17 ( V_32 ) ) ;
V_35 = V_32 ;
}
if ( ! V_26 && V_33 && V_33 -> type &&
! strcmp ( V_33 -> type , L_5 ) )
F_14 ( V_32 , V_33 ) ;
return 0 ;
case V_43 :
if ( V_32 == V_35 ||
( V_33 && V_33 == V_26 ) )
F_18 () ;
return 0 ;
}
return 0 ;
}
static int T_2 F_23 ( void )
{
F_24 ( & V_44 , & V_45 ) ;
return 0 ;
}
