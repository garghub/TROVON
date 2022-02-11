static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
struct V_7 * V_8 )
{
if ( F_2 ( ! V_6 ) )
return - V_9 ;
V_8 -> V_10 = V_5 - V_2 -> V_11 ;
V_8 -> V_12 = 0x10000000 ;
V_8 -> V_13 = 0 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_14 ;
const T_1 * V_15 = F_4 ( V_2 -> V_16 -> V_17 ,
L_1 , NULL ) ;
if ( ! V_15 )
return;
if ( F_5 ( V_2 -> V_16 -> V_17 , L_2 ) )
return;
V_2 -> V_11 = F_6 ( V_15 ) ;
V_2 -> V_18 = F_6 ( V_15 + 1 ) ;
V_14 = F_7 ( V_2 -> V_18 ) * sizeof( unsigned long ) ;
V_2 -> V_19 = F_8 ( V_14 , V_20 ) ;
if ( ! V_2 -> V_19 ) {
F_9 ( L_3 ,
V_2 -> V_16 -> V_21 ) ;
return;
}
V_2 -> V_22 = F_1 ;
V_2 -> V_23 = 0 ;
F_10 ( L_4 ,
V_2 -> V_18 , V_2 -> V_11 ) ;
}
static void F_3 ( struct V_1 * V_2 ) { }
static void T_2 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_24 )
{
if ( V_2 -> V_25 . V_26 . V_27 == NULL )
F_12 ( & V_2 -> V_25 . V_26 , V_2 -> V_16 -> V_28 ) ;
F_13 ( & V_24 -> V_4 , & V_2 -> V_25 . V_26 ) ;
}
static void T_3 F_14 ( struct V_29 * V_30 ,
void * V_31 , T_4 V_32 )
{
struct V_1 * V_2 ;
const T_4 * V_33 ;
T_4 V_34 ;
T_5 V_35 ;
static int V_36 = 1 ;
F_10 ( L_5 , V_30 -> V_37 ) ;
V_33 = F_4 ( V_30 , L_6 , NULL ) ;
if ( ! V_33 ) {
F_9 ( L_7 ) ;
return;
}
V_34 = F_15 ( V_33 ) ;
F_16 ( L_8 , V_34 ) ;
F_16 ( L_9 , F_17 ( V_31 ) ) ;
F_16 ( L_10 , V_32 ) ;
V_35 = F_18 ( V_34 , F_17 ( V_31 ) , V_32 ) ;
if ( V_35 != V_38 ) {
F_9 ( L_11 , V_35 ) ;
return;
}
V_2 = F_19 ( sizeof( struct V_1 ) ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_16 = F_20 ( V_30 ) ;
}
if ( ! V_2 || ! V_2 -> V_16 ) {
F_9 ( L_12 ) ;
return;
}
F_21 ( & V_2 -> V_39 ) ;
V_2 -> V_16 -> V_40 = 0 ;
V_2 -> V_16 -> V_41 = 0xff ;
V_2 -> V_16 -> V_42 = V_2 ;
V_2 -> V_43 = V_34 ;
V_2 -> type = V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = F_22 ( V_30 , 0 ) ;
if ( V_2 -> V_47 == NULL )
F_9 ( L_13 ) ;
else {
F_16 ( L_14 , F_23 ( V_2 -> V_47 + 0x100 ) ) ;
F_16 ( L_15 , F_23 ( V_2 -> V_47 + 0x1b0 ) ) ;
F_16 ( L_16 , F_23 ( V_2 -> V_47 + 0x1e0 ) ) ;
F_16 ( L_17 , F_23 ( V_2 -> V_47 + 0x1a0 ) ) ;
F_16 ( L_18 , F_23 ( V_2 -> V_47 + 0x190 ) ) ;
F_16 ( L_19 , F_23 ( V_2 -> V_47 + 0x1c0 ) ) ;
F_16 ( L_20 , F_23 ( V_2 -> V_47 + 0x1d0 ) ) ;
F_16 ( L_21 , F_23 ( V_2 -> V_47 + 0x2c0 ) ) ;
F_16 ( L_22 , F_23 ( V_2 -> V_47 + 0x2b0 ) ) ;
F_16 ( L_23 , F_23 ( V_2 -> V_47 + 0x2d0 ) ) ;
F_16 ( L_24 , F_23 ( V_2 -> V_47 + 0x2e0 ) ) ;
}
F_24 ( V_2 -> V_16 , V_30 , V_36 ) ;
V_36 = 0 ;
V_2 -> V_16 -> V_48 = & V_49 ;
F_3 ( V_2 ) ;
V_2 -> V_50 = F_11 ;
F_25 ( & V_2 -> V_25 . V_26 ,
V_31 , V_32 , 0 ) ;
}
void T_3 F_26 ( struct V_29 * V_30 )
{
struct V_29 * V_51 ;
const T_4 * V_33 ;
T_4 V_52 ;
void * V_31 ;
T_6 V_53 ;
T_5 V_35 ;
int V_54 = 0 ;
F_10 ( L_25 , V_30 -> V_37 ) ;
V_33 = F_4 ( V_30 , L_26 , NULL ) ;
if ( ! V_33 ) {
F_9 ( L_27 ) ;
return;
}
V_52 = F_15 ( V_33 ) ;
F_10 ( L_28 , V_52 ) ;
V_31 = F_27 ( V_55 , V_55 ,
F_17 ( V_56 ) ) ;
if ( ! V_31 ) {
F_9 ( L_29 ) ;
return;
}
F_28 ( L_30 ,
F_17 ( V_31 ) , F_17 ( V_31 ) + V_55 - 1 ) ;
V_35 = F_29 ( V_52 , F_17 ( V_31 ) ,
V_55 ) ;
if ( V_35 != V_38 ) {
F_9 ( L_31 , V_35 ) ;
return;
}
F_30 (np, phbn) {
if ( F_5 ( V_51 , L_2 ) ||
F_5 ( V_51 , L_32 ) )
V_54 ++ ;
}
V_53 = F_31 ( V_55 / V_54 ) ;
F_10 ( L_33 ,
V_53 >> 20 ) ;
F_30 (np, phbn) {
if ( F_5 ( V_51 , L_2 ) ||
F_5 ( V_51 , L_32 ) ) {
F_14 ( V_51 , V_31 , V_53 ) ;
V_31 += V_53 ;
}
}
}
