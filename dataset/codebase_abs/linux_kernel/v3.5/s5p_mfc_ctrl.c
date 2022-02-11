int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
void * V_6 ;
int V_7 ;
F_2 () ;
V_7 = F_3 ( ( const struct V_3 * * ) & V_4 ,
L_1 , V_2 -> V_8 . V_2 ) ;
if ( V_7 != 0 ) {
F_4 ( L_2 ) ;
return - V_9 ;
}
V_2 -> V_10 = F_5 ( V_4 -> V_11 , V_12 ) ;
if ( V_13 ) {
F_4 ( L_3 ) ;
F_6 ( V_4 ) ;
return - V_14 ;
}
V_13 = V_15 . V_16 (
V_2 -> V_17 [ V_18 ] , V_2 -> V_10 ) ;
if ( F_7 ( V_13 ) ) {
V_13 = NULL ;
F_4 ( L_4 ) ;
F_6 ( V_4 ) ;
return - V_14 ;
}
V_19 = F_8 (
V_2 -> V_17 [ V_18 ] , V_13 ) ;
if ( V_19 & ( ( 1 << V_20 ) - 1 ) ) {
F_4 ( L_5 ) ;
V_15 . V_21 ( V_13 ) ;
V_19 = 0 ;
V_13 = NULL ;
F_6 ( V_4 ) ;
return - V_22 ;
}
V_23 = V_15 . V_24 ( V_13 ) ;
if ( ! V_23 ) {
F_4 ( L_6 ) ;
V_15 . V_21 ( V_13 ) ;
V_19 = 0 ;
V_13 = NULL ;
F_6 ( V_4 ) ;
return - V_22 ;
}
V_2 -> V_25 = V_19 ;
V_6 = V_15 . V_16 (
V_2 -> V_17 [ V_26 ] , 1 << V_27 ) ;
if ( F_7 ( V_6 ) ) {
V_15 . V_21 ( V_13 ) ;
V_19 = 0 ;
V_13 = NULL ;
F_4 ( L_7 ) ;
F_6 ( V_4 ) ;
return - V_14 ;
}
V_5 = F_8 (
V_2 -> V_17 [ V_26 ] , V_6 ) ;
V_15 . V_21 ( V_6 ) ;
if ( V_5 & ( ( 1 << V_20 ) - 1 ) ) {
F_4 ( L_8 ) ;
V_15 . V_21 ( V_13 ) ;
V_19 = 0 ;
V_13 = NULL ;
F_6 ( V_4 ) ;
return - V_22 ;
}
V_2 -> V_28 = V_5 ;
memcpy ( V_23 , V_4 -> V_29 , V_4 -> V_11 ) ;
F_9 () ;
F_6 ( V_4 ) ;
F_10 () ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
F_2 () ;
V_7 = F_3 ( ( const struct V_3 * * ) & V_4 ,
L_1 , V_2 -> V_8 . V_2 ) ;
if ( V_7 != 0 ) {
F_4 ( L_2 ) ;
return - V_9 ;
}
if ( V_4 -> V_11 > V_2 -> V_10 ) {
F_4 ( L_9 ) ;
F_6 ( V_4 ) ;
return - V_14 ;
}
if ( V_13 == NULL || V_19 == 0 ) {
F_4 ( L_10 ) ;
F_6 ( V_4 ) ;
return - V_9 ;
}
memcpy ( V_23 , V_4 -> V_29 , V_4 -> V_11 ) ;
F_9 () ;
F_6 ( V_4 ) ;
F_10 () ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
if ( ! V_13 )
return - V_9 ;
V_15 . V_21 ( V_13 ) ;
V_23 = NULL ;
V_19 = 0 ;
V_13 = NULL ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
unsigned long V_31 ;
F_2 () ;
F_14 ( V_2 , 0x3f6 , V_32 ) ;
F_14 ( V_2 , 0x3e2 , V_32 ) ;
F_15 ( 10 ) ;
V_31 = V_33 + F_16 ( V_34 ) ;
do {
if ( F_17 ( V_33 , V_31 ) ) {
F_4 ( L_11 ) ;
return - V_22 ;
}
V_30 = F_18 ( V_2 , V_35 ) ;
} while ( V_30 & 0x3 );
F_14 ( V_2 , 0x0 , V_32 ) ;
F_14 ( V_2 , 0x3fe , V_32 ) ;
F_10 () ;
return 0 ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_2 -> V_25 , V_36 ) ;
F_14 ( V_2 , V_2 -> V_28 , V_37 ) ;
F_20 ( 2 , L_12 , V_2 -> V_25 , V_2 -> V_28 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
F_14 ( V_2 , 0xffffffff , V_38 ) ;
F_14 ( V_2 , 0xffffffff , V_39 ) ;
F_14 ( V_2 , 0 , V_40 ) ;
F_14 ( V_2 , 0 , V_41 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned int V_42 ;
int V_43 ;
F_2 () ;
if ( ! V_13 )
return - V_9 ;
F_20 ( 2 , L_13 ) ;
F_23 () ;
V_43 = F_13 ( V_2 ) ;
if ( V_43 ) {
F_4 ( L_14 ) ;
return V_43 ;
}
F_20 ( 2 , L_15 ) ;
F_19 ( V_2 ) ;
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
F_14 ( V_2 , 0x3ff , V_32 ) ;
F_20 ( 2 , L_16 ) ;
if ( F_25 ( V_2 , V_44 ) ) {
F_4 ( L_17 ) ;
F_13 ( V_2 ) ;
F_26 () ;
return - V_22 ;
}
F_24 ( V_2 ) ;
V_43 = F_27 ( V_2 ) ;
if ( V_43 ) {
F_4 ( L_18 ) ;
F_13 ( V_2 ) ;
F_26 () ;
return V_43 ;
}
F_20 ( 2 , L_19 ) ;
if ( F_25 ( V_2 , V_45 ) ) {
F_4 ( L_17 ) ;
F_13 ( V_2 ) ;
F_26 () ;
return - V_22 ;
}
V_2 -> V_46 = 0 ;
if ( V_2 -> V_47 != 0 || V_2 -> V_48 !=
V_45 ) {
F_4 ( L_20 ,
V_2 -> V_47 , V_2 -> V_48 ) ;
F_13 ( V_2 ) ;
F_26 () ;
return - V_22 ;
}
V_42 = F_18 ( V_2 , V_49 ) ;
F_20 ( 2 , L_21 ,
( V_42 >> 16 ) & 0xFF , ( V_42 >> 8 ) & 0xFF , V_42 & 0xFF ) ;
F_26 () ;
F_10 () ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_43 ;
F_2 () ;
F_23 () ;
F_24 ( V_2 ) ;
V_43 = F_29 ( V_2 ) ;
if ( V_43 ) {
F_4 ( L_18 ) ;
return V_43 ;
}
if ( F_25 ( V_2 , V_50 ) ) {
F_4 ( L_22 ) ;
return - V_22 ;
}
F_26 () ;
V_2 -> V_46 = 0 ;
if ( V_2 -> V_47 != 0 || V_2 -> V_48 !=
V_50 ) {
F_4 ( L_23 , V_2 -> V_47 ,
V_2 -> V_48 ) ;
return - V_22 ;
}
F_10 () ;
return V_43 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_43 ;
F_2 () ;
F_20 ( 2 , L_13 ) ;
F_23 () ;
V_43 = F_13 ( V_2 ) ;
if ( V_43 ) {
F_4 ( L_14 ) ;
return V_43 ;
}
F_20 ( 2 , L_15 ) ;
F_19 ( V_2 ) ;
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
V_43 = F_31 ( V_2 ) ;
if ( V_43 ) {
F_4 ( L_18 ) ;
return V_43 ;
}
F_14 ( V_2 , 0x3ff , V_32 ) ;
F_20 ( 2 , L_24 ) ;
if ( F_25 ( V_2 , V_51 ) ) {
F_4 ( L_17 ) ;
return - V_22 ;
}
F_26 () ;
V_2 -> V_46 = 0 ;
if ( V_2 -> V_47 != 0 || V_2 -> V_48 !=
V_51 ) {
F_4 ( L_25 , V_2 -> V_47 ,
V_2 -> V_48 ) ;
return - V_22 ;
}
F_10 () ;
return 0 ;
}
