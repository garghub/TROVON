int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
void * V_6 ;
int V_7 ;
F_2 () ;
V_7 = F_3 ( ( const struct V_3 * * ) & V_4 ,
V_2 -> V_8 -> V_9 , V_2 -> V_10 . V_2 ) ;
if ( V_7 != 0 ) {
F_4 ( L_1 ) ;
return - V_11 ;
}
V_2 -> V_12 = V_2 -> V_8 -> V_13 -> V_14 ;
if ( V_4 -> V_15 > V_2 -> V_12 ) {
F_4 ( L_2 ) ;
F_5 ( V_4 ) ;
return - V_16 ;
}
if ( V_17 ) {
F_4 ( L_3 ) ;
F_5 ( V_4 ) ;
return - V_16 ;
}
V_17 = V_18 . V_19 (
V_2 -> V_20 [ V_21 ] , V_2 -> V_12 ) ;
if ( F_6 ( V_17 ) ) {
V_17 = NULL ;
F_4 ( L_4 ) ;
F_5 ( V_4 ) ;
return - V_16 ;
}
V_22 = F_7 (
V_2 -> V_20 [ V_21 ] , V_17 ) ;
if ( V_22 & ( ( 1 << V_23 ) - 1 ) ) {
F_4 ( L_5 ) ;
V_18 . V_24 ( V_17 ) ;
V_22 = 0 ;
V_17 = NULL ;
F_5 ( V_4 ) ;
return - V_25 ;
}
V_26 = V_18 . V_27 ( V_17 ) ;
if ( ! V_26 ) {
F_4 ( L_6 ) ;
V_18 . V_24 ( V_17 ) ;
V_22 = 0 ;
V_17 = NULL ;
F_5 ( V_4 ) ;
return - V_25 ;
}
V_2 -> V_28 = V_22 ;
if ( F_8 ( V_2 ) && F_9 ( V_2 ) ) {
V_6 = V_18 . V_19 (
V_2 -> V_20 [ V_29 ] ,
1 << V_23 ) ;
if ( F_6 ( V_6 ) ) {
V_18 . V_24 ( V_17 ) ;
V_22 = 0 ;
V_17 = NULL ;
F_4 ( L_7 ) ;
F_5 ( V_4 ) ;
return - V_16 ;
}
V_5 = F_7 (
V_2 -> V_20 [ V_29 ] , V_6 ) ;
V_18 . V_24 ( V_6 ) ;
if ( V_5 & ( ( 1 << V_23 ) - 1 ) ) {
F_4 ( L_8 ) ;
V_18 . V_24 ( V_17 ) ;
V_22 = 0 ;
V_17 = NULL ;
F_5 ( V_4 ) ;
return - V_25 ;
}
V_2 -> V_30 = V_5 - ( 1 << V_23 ) ;
} else {
V_2 -> V_30 = V_2 -> V_28 ;
}
memcpy ( V_26 , V_4 -> V_31 , V_4 -> V_15 ) ;
F_10 () ;
F_5 ( V_4 ) ;
F_11 () ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
F_2 () ;
V_7 = F_3 ( ( const struct V_3 * * ) & V_4 ,
V_2 -> V_8 -> V_9 , V_2 -> V_10 . V_2 ) ;
if ( V_7 != 0 ) {
F_4 ( L_1 ) ;
return - V_11 ;
}
if ( V_4 -> V_15 > V_2 -> V_12 ) {
F_4 ( L_2 ) ;
F_5 ( V_4 ) ;
return - V_16 ;
}
if ( V_17 == NULL || V_22 == 0 ) {
F_4 ( L_9 ) ;
F_5 ( V_4 ) ;
return - V_11 ;
}
memcpy ( V_26 , V_4 -> V_31 , V_4 -> V_15 ) ;
F_10 () ;
F_5 ( V_4 ) ;
F_11 () ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( ! V_17 )
return - V_11 ;
V_18 . V_24 ( V_17 ) ;
V_26 = NULL ;
V_22 = 0 ;
V_17 = NULL ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
unsigned int V_32 ;
unsigned long V_33 ;
int V_34 ;
F_2 () ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 , 0xFEE , V_35 ) ;
F_16 ( V_2 , 0x0 , V_35 ) ;
F_16 ( V_2 , 0 , V_36 ) ;
F_16 ( V_2 , 0 , V_37 ) ;
F_16 ( V_2 , 0 , V_38 ) ;
for ( V_34 = 0 ; V_34 < V_39 ; V_34 ++ )
F_16 ( V_2 , 0 , V_40 + ( V_34 * 4 ) ) ;
F_16 ( V_2 , 0 , V_41 ) ;
F_16 ( V_2 , 0x1FFF , V_35 ) ;
F_16 ( V_2 , 0 , V_35 ) ;
} else {
F_16 ( V_2 , 0x3f6 , V_42 ) ;
F_16 ( V_2 , 0x3e2 , V_42 ) ;
F_17 ( 10 ) ;
V_33 = V_43 + F_18 ( V_44 ) ;
do {
if ( F_19 ( V_43 , V_33 ) ) {
F_4 ( L_10 ) ;
return - V_25 ;
}
V_32 = F_20 ( V_2 , V_45 ) ;
} while ( V_32 & 0x3 );
F_16 ( V_2 , 0x0 , V_42 ) ;
F_16 ( V_2 , 0x3fe , V_42 ) ;
}
F_11 () ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 , V_2 -> V_28 , V_46 ) ;
F_22 ( 2 , L_11 , V_2 -> V_28 ) ;
} else {
F_16 ( V_2 , V_2 -> V_28 , V_47 ) ;
F_16 ( V_2 , V_2 -> V_30 , V_48 ) ;
F_22 ( 2 , L_12 ,
V_2 -> V_28 , V_2 -> V_30 ) ;
}
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) ) {
} else {
F_16 ( V_2 , 0xffffffff , V_49 ) ;
F_16 ( V_2 , 0xffffffff , V_50 ) ;
F_16 ( V_2 , 0 , V_51 ) ;
F_16 ( V_2 , 0 , V_52 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
unsigned int V_53 ;
int V_54 ;
F_2 () ;
if ( ! V_17 )
return - V_11 ;
F_22 ( 2 , L_13 ) ;
F_25 () ;
V_54 = F_14 ( V_2 ) ;
if ( V_54 ) {
F_4 ( L_14 ) ;
return V_54 ;
}
F_22 ( 2 , L_15 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( F_15 ( V_2 ) )
F_16 ( V_2 , 0x1 , V_41 ) ;
else
F_16 ( V_2 , 0x3ff , V_42 ) ;
F_22 ( 2 , L_16 ) ;
if ( F_27 ( V_2 , V_55 ) ) {
F_4 ( L_17 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return - V_25 ;
}
F_26 ( V_2 ) ;
V_54 = F_29 ( V_2 -> V_56 , V_57 , V_2 ) ;
if ( V_54 ) {
F_4 ( L_18 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return V_54 ;
}
F_22 ( 2 , L_19 ) ;
if ( F_27 ( V_2 , V_58 ) ) {
F_4 ( L_17 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return - V_25 ;
}
V_2 -> V_59 = 0 ;
if ( V_2 -> V_60 != 0 || V_2 -> V_61 !=
V_58 ) {
F_4 ( L_20 ,
V_2 -> V_60 , V_2 -> V_61 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return - V_25 ;
}
if ( F_15 ( V_2 ) )
V_53 = F_20 ( V_2 , V_38 ) ;
else
V_53 = F_20 ( V_2 , V_62 ) ;
F_22 ( 2 , L_21 ,
( V_53 >> 16 ) & 0xFF , ( V_53 >> 8 ) & 0xFF , V_53 & 0xFF ) ;
F_28 () ;
F_11 () ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_25 () ;
F_14 ( V_2 ) ;
F_29 ( V_2 -> V_63 , V_64 , V_2 ) ;
F_28 () ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_54 ;
F_2 () ;
F_25 () ;
F_26 ( V_2 ) ;
V_54 = F_29 ( V_2 -> V_56 , V_65 , V_2 ) ;
if ( V_54 ) {
F_4 ( L_18 ) ;
return V_54 ;
}
if ( F_27 ( V_2 , V_66 ) ) {
F_4 ( L_22 ) ;
return - V_25 ;
}
F_28 () ;
V_2 -> V_59 = 0 ;
if ( V_2 -> V_60 != 0 || V_2 -> V_61 !=
V_66 ) {
F_4 ( L_23 , V_2 -> V_60 ,
V_2 -> V_61 ) ;
return - V_25 ;
}
F_11 () ;
return V_54 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_54 ;
F_2 () ;
F_22 ( 2 , L_13 ) ;
F_25 () ;
V_54 = F_14 ( V_2 ) ;
if ( V_54 ) {
F_4 ( L_14 ) ;
return V_54 ;
}
F_22 ( 2 , L_15 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
V_54 = F_29 ( V_2 -> V_56 , V_67 , V_2 ) ;
if ( V_54 ) {
F_4 ( L_18 ) ;
return V_54 ;
}
if ( F_15 ( V_2 ) )
F_16 ( V_2 , 0x1 , V_41 ) ;
else
F_16 ( V_2 , 0x3ff , V_42 ) ;
F_22 ( 2 , L_24 ) ;
if ( F_27 ( V_2 , V_68 ) ) {
F_4 ( L_17 ) ;
return - V_25 ;
}
F_28 () ;
V_2 -> V_59 = 0 ;
if ( V_2 -> V_60 != 0 || V_2 -> V_61 !=
V_68 ) {
F_4 ( L_25 , V_2 -> V_60 ,
V_2 -> V_61 ) ;
return - V_25 ;
}
F_11 () ;
return 0 ;
}
