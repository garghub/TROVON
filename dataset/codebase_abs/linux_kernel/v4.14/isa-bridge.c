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
F_13 ( L_6 , V_23 ) ;
}
void T_2 F_14 ( struct V_1 * V_23 )
{
const T_3 * V_30 , * V_31 = NULL ;
int V_14 , V_32 , V_33 ;
T_1 V_34 , V_35 , V_36 ;
T_4 V_37 , V_38 , V_12 = 0 ;
if ( V_26 != NULL )
return;
V_36 = F_15 ( V_23 ) ;
if ( F_16 ( V_23 , L_7 , & V_34 ) ||
F_16 ( V_23 , L_8 , & V_35 ) ) {
F_17 ( L_9 ,
V_23 ) ;
return;
}
if ( V_34 != 2 || V_35 != 1 ) {
F_17 ( L_10 ,
V_23 ) ;
return;
}
V_33 = V_34 + V_35 + V_36 ;
V_30 = F_2 ( V_23 , L_1 , & V_14 ) ;
if ( V_30 == NULL || V_14 < V_33 ) {
F_17 ( L_11 ,
V_23 ) ;
return;
}
for ( V_32 = 0 ; ( V_32 + V_33 - 1 ) < V_14 ; V_32 += V_33 ) {
if ( F_18 ( V_30 + V_32 ) != 1 )
continue;
V_37 = F_18 ( V_30 + V_32 + 1 ) ;
V_12 = F_19 ( V_30 + V_32 + V_34 + V_36 , V_35 ) ;
V_31 = V_30 + V_32 + V_34 ;
break;
}
if ( ! V_12 || ! V_31 ) {
F_17 ( L_12 ,
V_23 ) ;
return;
}
V_12 = F_4 ( V_12 ) ;
if ( V_12 > 0x10000 )
V_12 = 0x10000 ;
V_38 = F_20 ( V_23 , V_31 ) ;
if ( V_38 == V_39 ) {
F_17 ( L_13 ,
V_23 ) ;
return;
}
if ( ( V_37 & ~ V_40 ) || ( V_38 & ~ V_40 ) ) {
F_17 ( L_14 ,
V_23 ) ;
return;
}
V_26 = V_23 ;
V_29 = V_20 ;
F_5 ( V_38 , ( void * ) V_20 ,
V_12 , F_6 ( F_7 ( F_8 ( 0 ) ) ) ) ;
F_13 ( L_15 , V_23 ) ;
}
static void F_21 ( struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_21 * V_22 = F_22 ( V_42 -> V_44 ) ;
V_26 = F_23 ( V_43 ) ;
V_45 = V_42 ;
F_1 ( V_43 , V_22 -> V_28 ) ;
V_29 = V_20 ;
F_13 ( L_16 ,
V_43 , F_24 ( V_42 ) ) ;
}
static void F_25 ( void )
{
F_13 ( L_17 ) ;
V_29 = V_20 ;
F_12 ( V_26 ) ;
V_26 = NULL ;
V_45 = NULL ;
F_26 ( ( void * ) V_20 , 0x10000 ) ;
}
static int F_27 ( struct V_46 * V_47 , unsigned long V_48 ,
void * V_49 )
{
struct V_50 * V_51 = V_49 ;
struct V_41 * V_42 = F_28 ( V_51 ) ;
struct V_1 * V_43 = F_29 ( V_42 ) ;
switch( V_48 ) {
case V_52 :
if ( V_26 && V_26 == V_43 &&
! V_45 ) {
F_13 ( L_18 ,
F_24 ( V_42 ) ) ;
V_45 = V_42 ;
}
if ( ! V_26 && V_43 && V_43 -> type &&
! strcmp ( V_43 -> type , L_5 ) )
F_21 ( V_42 , V_43 ) ;
return 0 ;
case V_53 :
if ( V_42 == V_45 ||
( V_43 && V_43 == V_26 ) )
F_25 () ;
return 0 ;
}
return 0 ;
}
static int T_2 F_30 ( void )
{
F_31 ( & V_54 , & V_55 ) ;
return 0 ;
}
