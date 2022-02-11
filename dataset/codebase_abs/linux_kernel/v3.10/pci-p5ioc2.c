static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int V_7 , struct V_8 * V_9 )
{
if ( F_2 ( ! V_7 ) )
return - V_10 ;
V_9 -> V_11 = V_5 - V_2 -> V_12 ;
V_9 -> V_13 = 0x10000000 ;
V_9 -> V_14 = 0 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
const T_1 * V_16 = F_4 ( V_2 -> V_17 -> V_18 ,
L_1 , NULL ) ;
if ( ! V_16 )
return;
if ( F_5 ( V_2 -> V_17 -> V_18 , L_2 ) )
return;
V_2 -> V_12 = F_6 ( V_16 ) ;
V_15 = F_6 ( V_16 + 1 ) ;
if ( F_7 ( & V_2 -> V_19 , V_15 , V_2 -> V_17 -> V_18 ) ) {
F_8 ( L_3 ,
V_2 -> V_17 -> V_20 ) ;
return;
}
V_2 -> V_21 = F_1 ;
V_2 -> V_22 = 0 ;
F_9 ( L_4 ,
V_15 , V_2 -> V_12 ) ;
}
static void F_3 ( struct V_1 * V_2 ) { }
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_23 )
{
if ( V_2 -> V_24 . V_25 . V_26 == NULL )
F_11 ( & V_2 -> V_24 . V_25 , V_2 -> V_17 -> V_27 ) ;
F_12 ( & V_23 -> V_4 , & V_2 -> V_24 . V_25 ) ;
}
static void T_2 F_13 ( struct V_28 * V_29 ,
void * V_30 , T_3 V_31 )
{
struct V_1 * V_2 ;
const T_3 * V_32 ;
T_3 V_33 ;
T_4 V_34 ;
static int V_35 = 1 ;
F_9 ( L_5 , V_29 -> V_36 ) ;
V_32 = F_4 ( V_29 , L_6 , NULL ) ;
if ( ! V_32 ) {
F_8 ( L_7 ) ;
return;
}
V_33 = F_14 ( V_32 ) ;
F_15 ( L_8 , V_33 ) ;
F_15 ( L_9 , F_16 ( V_30 ) ) ;
F_15 ( L_10 , V_31 ) ;
V_34 = F_17 ( V_33 , F_16 ( V_30 ) , V_31 ) ;
if ( V_34 != V_37 ) {
F_8 ( L_11 , V_34 ) ;
return;
}
V_2 = F_18 ( sizeof( struct V_1 ) ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_17 = F_19 ( V_29 ) ;
}
if ( ! V_2 || ! V_2 -> V_17 ) {
F_8 ( L_12 ) ;
return;
}
F_20 ( & V_2 -> V_38 ) ;
V_2 -> V_17 -> V_39 = 0 ;
V_2 -> V_17 -> V_40 = 0xff ;
V_2 -> V_17 -> V_41 = V_2 ;
V_2 -> V_42 = V_33 ;
V_2 -> type = V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = F_21 ( V_29 , 0 ) ;
if ( V_2 -> V_46 == NULL )
F_8 ( L_13 ) ;
else {
F_15 ( L_14 , F_22 ( V_2 -> V_46 + 0x100 ) ) ;
F_15 ( L_15 , F_22 ( V_2 -> V_46 + 0x1b0 ) ) ;
F_15 ( L_16 , F_22 ( V_2 -> V_46 + 0x1e0 ) ) ;
F_15 ( L_17 , F_22 ( V_2 -> V_46 + 0x1a0 ) ) ;
F_15 ( L_18 , F_22 ( V_2 -> V_46 + 0x190 ) ) ;
F_15 ( L_19 , F_22 ( V_2 -> V_46 + 0x1c0 ) ) ;
F_15 ( L_20 , F_22 ( V_2 -> V_46 + 0x1d0 ) ) ;
F_15 ( L_21 , F_22 ( V_2 -> V_46 + 0x2c0 ) ) ;
F_15 ( L_22 , F_22 ( V_2 -> V_46 + 0x2b0 ) ) ;
F_15 ( L_23 , F_22 ( V_2 -> V_46 + 0x2d0 ) ) ;
F_15 ( L_24 , F_22 ( V_2 -> V_46 + 0x2e0 ) ) ;
}
F_23 ( V_2 -> V_17 , V_29 , V_35 ) ;
V_35 = 0 ;
V_2 -> V_17 -> V_47 = & V_48 ;
F_3 ( V_2 ) ;
V_2 -> V_49 = F_10 ;
F_24 ( & V_2 -> V_24 . V_25 ,
V_30 , V_31 , 0 ) ;
}
void T_2 F_25 ( struct V_28 * V_29 )
{
struct V_28 * V_50 ;
const T_3 * V_32 ;
T_3 V_51 ;
void * V_30 ;
T_5 V_52 ;
T_4 V_34 ;
int V_53 = 0 ;
F_9 ( L_25 , V_29 -> V_36 ) ;
V_32 = F_4 ( V_29 , L_26 , NULL ) ;
if ( ! V_32 ) {
F_8 ( L_27 ) ;
return;
}
V_51 = F_14 ( V_32 ) ;
F_9 ( L_28 , V_51 ) ;
V_30 = F_26 ( V_54 , V_54 ,
F_16 ( V_55 ) ) ;
if ( ! V_30 ) {
F_8 ( L_29 ) ;
return;
}
F_27 ( L_30 ,
F_16 ( V_30 ) , F_16 ( V_30 ) + V_54 - 1 ) ;
V_34 = F_28 ( V_51 , F_16 ( V_30 ) ,
V_54 ) ;
if ( V_34 != V_37 ) {
F_8 ( L_31 , V_34 ) ;
return;
}
F_29 (np, phbn) {
if ( F_5 ( V_50 , L_2 ) ||
F_5 ( V_50 , L_32 ) )
V_53 ++ ;
}
V_52 = F_30 ( V_54 / V_53 ) ;
F_9 ( L_33 ,
V_52 >> 20 ) ;
F_29 (np, phbn) {
if ( F_5 ( V_50 , L_2 ) ||
F_5 ( V_50 , L_32 ) ) {
F_13 ( V_50 , V_30 , V_52 ) ;
V_30 += V_52 ;
}
}
}
