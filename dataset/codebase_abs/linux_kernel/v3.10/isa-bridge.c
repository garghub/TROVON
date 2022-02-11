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
V_12 , V_21 | V_22 ) ;
return;
V_15:
F_3 ( V_18 L_3
L_4 ) ;
F_5 ( V_3 , ( void * ) V_20 ,
0x10000 , V_21 | V_22 ) ;
}
void T_2 F_6 ( struct V_23 * V_24 )
{
struct V_1 * V_25 , * V_26 = NULL , * V_27 ;
if ( V_28 != NULL )
return;
F_7 (np, L_5 ) {
for ( V_26 = F_8 ( V_25 ) ; V_26 ; ) {
if ( V_26 == V_24 -> V_29 ) {
F_9 ( V_26 ) ;
break;
}
V_27 = V_26 ;
V_26 = F_8 ( V_26 ) ;
F_9 ( V_27 ) ;
}
if ( V_26 != NULL )
break;
}
if ( V_25 == NULL )
return;
V_28 = V_25 ;
F_1 ( V_25 , V_24 -> V_30 ) ;
V_31 = V_20 ;
F_10 ( L_6 , V_25 -> V_32 ) ;
}
static void F_11 ( struct V_33 * V_34 ,
struct V_1 * V_35 )
{
struct V_23 * V_24 = F_12 ( V_34 -> V_36 ) ;
V_28 = F_13 ( V_35 ) ;
V_37 = V_34 ;
F_1 ( V_35 , V_24 -> V_30 ) ;
V_31 = V_20 ;
F_10 ( L_7 ,
V_35 -> V_32 , F_14 ( V_34 ) ) ;
}
static void F_15 ( void )
{
F_10 ( L_8 ) ;
V_31 = V_20 ;
F_9 ( V_28 ) ;
V_28 = NULL ;
V_37 = NULL ;
F_16 ( ( void * ) V_20 , 0x10000 ) ;
}
static int F_17 ( struct V_38 * V_39 , unsigned long V_40 ,
void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_33 * V_34 = F_18 ( V_43 ) ;
struct V_1 * V_35 = F_19 ( V_34 ) ;
switch( V_40 ) {
case V_44 :
if ( V_28 && V_28 == V_35 &&
! V_37 ) {
F_10 ( L_9 ,
F_14 ( V_34 ) ) ;
V_37 = V_34 ;
}
if ( ! V_28 && V_35 && V_35 -> type &&
! strcmp ( V_35 -> type , L_5 ) )
F_11 ( V_34 , V_35 ) ;
return 0 ;
case V_45 :
if ( V_34 == V_37 ||
( V_35 && V_35 == V_28 ) )
F_15 () ;
return 0 ;
}
return 0 ;
}
static int T_2 F_20 ( void )
{
F_21 ( & V_46 , & V_47 ) ;
return 0 ;
}
