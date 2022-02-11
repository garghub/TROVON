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
if ( V_2 -> V_24 . V_25 . V_26 == NULL ) {
F_11 ( & V_2 -> V_24 . V_25 , V_2 -> V_17 -> V_27 ) ;
F_12 ( & V_2 -> V_24 . V_25 ,
F_13 ( V_2 -> V_17 -> V_28 ) , V_2 -> V_29 ) ;
}
F_14 ( & V_23 -> V_4 , & V_2 -> V_24 . V_25 ) ;
}
static void T_2 F_15 ( struct V_30 * V_31 , T_3 V_32 ,
void * V_33 , T_3 V_34 )
{
struct V_1 * V_2 ;
const T_4 * V_35 ;
T_3 V_36 ;
T_5 V_37 ;
static int V_38 = 1 ;
F_9 ( L_5 , V_31 -> V_39 ) ;
V_35 = F_4 ( V_31 , L_6 , NULL ) ;
if ( ! V_35 ) {
F_8 ( L_7 ) ;
return;
}
V_36 = F_16 ( V_35 ) ;
F_17 ( L_8 , V_36 ) ;
F_17 ( L_9 , F_18 ( V_33 ) ) ;
F_17 ( L_10 , V_34 ) ;
V_37 = F_19 ( V_36 , F_18 ( V_33 ) , V_34 ) ;
if ( V_37 != V_40 ) {
F_8 ( L_11 , V_37 ) ;
return;
}
V_2 = F_20 ( sizeof( struct V_1 ) , 0 ) ;
V_2 -> V_17 = F_21 ( V_31 ) ;
if ( ! V_2 -> V_17 ) {
F_8 ( L_12 ) ;
return;
}
F_22 ( & V_2 -> V_41 ) ;
V_2 -> V_17 -> V_42 = 0 ;
V_2 -> V_17 -> V_43 = 0xff ;
V_2 -> V_17 -> V_44 = V_2 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_29 = V_36 ;
V_2 -> type = V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 = F_23 ( V_31 , 0 ) ;
if ( V_2 -> V_48 == NULL )
F_8 ( L_13 ) ;
else {
F_17 ( L_14 , F_24 ( V_2 -> V_48 + 0x100 ) ) ;
F_17 ( L_15 , F_24 ( V_2 -> V_48 + 0x1b0 ) ) ;
F_17 ( L_16 , F_24 ( V_2 -> V_48 + 0x1e0 ) ) ;
F_17 ( L_17 , F_24 ( V_2 -> V_48 + 0x1a0 ) ) ;
F_17 ( L_18 , F_24 ( V_2 -> V_48 + 0x190 ) ) ;
F_17 ( L_19 , F_24 ( V_2 -> V_48 + 0x1c0 ) ) ;
F_17 ( L_20 , F_24 ( V_2 -> V_48 + 0x1d0 ) ) ;
F_17 ( L_21 , F_24 ( V_2 -> V_48 + 0x2c0 ) ) ;
F_17 ( L_22 , F_24 ( V_2 -> V_48 + 0x2b0 ) ) ;
F_17 ( L_23 , F_24 ( V_2 -> V_48 + 0x2d0 ) ) ;
F_17 ( L_24 , F_24 ( V_2 -> V_48 + 0x2e0 ) ) ;
}
F_25 ( V_2 -> V_17 , V_31 , V_38 ) ;
V_38 = 0 ;
V_2 -> V_17 -> V_49 = & V_50 ;
F_3 ( V_2 ) ;
V_2 -> V_51 = F_10 ;
F_26 ( & V_2 -> V_24 . V_25 ,
V_33 , V_34 , 0 ,
V_52 ) ;
}
void T_2 F_27 ( struct V_30 * V_31 )
{
struct V_30 * V_53 ;
const T_4 * V_35 ;
T_3 V_32 ;
void * V_33 ;
T_6 V_54 ;
T_5 V_37 ;
int V_55 = 0 ;
F_9 ( L_25 , V_31 -> V_39 ) ;
V_35 = F_4 ( V_31 , L_26 , NULL ) ;
if ( ! V_35 ) {
F_8 ( L_27 ) ;
return;
}
V_32 = F_16 ( V_35 ) ;
F_9 ( L_28 , V_32 ) ;
F_28 (np, phbn) {
if ( F_5 ( V_53 , L_2 ) ||
F_5 ( V_53 , L_29 ) )
V_55 ++ ;
}
if ( V_55 <= 0 ) {
F_9 ( L_30 , V_31 -> V_39 ) ;
return;
}
V_54 = F_29 ( V_56 / V_55 ) ;
F_9 ( L_31 ,
V_54 >> 20 ) ;
V_33 = F_20 ( V_56 , V_56 ) ;
F_30 ( L_32 ,
F_18 ( V_33 ) , F_18 ( V_33 ) + V_56 - 1 ) ;
V_37 = F_31 ( V_32 , F_18 ( V_33 ) ,
V_56 ) ;
if ( V_37 != V_40 ) {
F_8 ( L_33 , V_37 ) ;
return;
}
F_28 (np, phbn) {
if ( F_5 ( V_53 , L_2 ) ||
F_5 ( V_53 , L_29 ) ) {
F_15 ( V_53 , V_32 ,
V_33 , V_54 ) ;
V_33 += V_54 ;
}
}
}
