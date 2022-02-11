int F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
T_1 V_4 ;
V_2 -> V_5 = V_2 -> V_6 -> V_7 -> V_8 ;
if ( V_2 -> V_9 ) {
F_2 ( L_1 ) ;
return - V_10 ;
}
V_2 -> V_9 = F_3 ( V_2 -> V_11 , V_2 -> V_5 ,
& V_2 -> V_12 , V_13 ) ;
if ( F_4 ( V_2 -> V_9 ) ) {
V_2 -> V_9 = NULL ;
F_2 ( L_2 ) ;
return - V_10 ;
}
V_2 -> V_12 = V_2 -> V_12 ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) ) {
V_3 = F_3 ( V_2 -> V_14 , 1 << V_15 ,
& V_4 , V_13 ) ;
if ( F_7 ( V_2 -> V_9 ) ) {
F_2 ( L_3 ) ;
F_8 ( V_2 -> V_11 , V_2 -> V_5 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
V_2 -> V_9 = NULL ;
return - V_10 ;
}
V_2 -> V_16 = V_4 - ( 1 << V_15 ) ;
F_8 ( V_2 -> V_14 , 1 << V_15 ,
V_3 , V_4 ) ;
} else {
V_2 -> V_16 = V_2 -> V_12 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_19 ;
F_10 () ;
V_19 = F_11 ( ( const struct V_17 * * ) & V_18 ,
V_2 -> V_6 -> V_20 , V_2 -> V_21 . V_2 ) ;
if ( V_19 != 0 ) {
F_2 ( L_4 ) ;
return - V_22 ;
}
if ( V_18 -> V_23 > V_2 -> V_5 ) {
F_2 ( L_5 ) ;
F_12 ( V_18 ) ;
return - V_10 ;
}
if ( ! V_2 -> V_9 ) {
F_2 ( L_6 ) ;
F_12 ( V_18 ) ;
return - V_22 ;
}
memcpy ( V_2 -> V_9 , V_18 -> V_24 , V_18 -> V_23 ) ;
F_13 () ;
F_12 ( V_18 ) ;
F_14 () ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_19 ;
F_10 () ;
V_19 = F_11 ( ( const struct V_17 * * ) & V_18 ,
V_2 -> V_6 -> V_20 , V_2 -> V_21 . V_2 ) ;
if ( V_19 != 0 ) {
F_2 ( L_4 ) ;
return - V_22 ;
}
if ( V_18 -> V_23 > V_2 -> V_5 ) {
F_2 ( L_5 ) ;
F_12 ( V_18 ) ;
return - V_10 ;
}
if ( ! V_2 -> V_9 ) {
F_2 ( L_6 ) ;
F_12 ( V_18 ) ;
return - V_22 ;
}
memcpy ( V_2 -> V_9 , V_18 -> V_24 , V_18 -> V_23 ) ;
F_13 () ;
F_12 ( V_18 ) ;
F_14 () ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 )
return - V_22 ;
F_8 ( V_2 -> V_11 , V_2 -> V_5 , V_2 -> V_9 ,
V_2 -> V_12 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
unsigned int V_25 ;
unsigned long V_26 ;
int V_27 ;
F_10 () ;
if ( F_18 ( V_2 ) ) {
F_19 ( V_2 , 0xFEE , V_28 ) ;
F_19 ( V_2 , 0x0 , V_28 ) ;
F_19 ( V_2 , 0 , V_29 ) ;
F_19 ( V_2 , 0 , V_30 ) ;
F_19 ( V_2 , 0 , V_31 ) ;
for ( V_27 = 0 ; V_27 < V_32 ; V_27 ++ )
F_19 ( V_2 , 0 , V_33 + ( V_27 * 4 ) ) ;
F_19 ( V_2 , 0 , V_34 ) ;
F_19 ( V_2 , 0x1FFF , V_28 ) ;
F_19 ( V_2 , 0 , V_28 ) ;
} else {
F_19 ( V_2 , 0x3f6 , V_35 ) ;
F_19 ( V_2 , 0x3e2 , V_35 ) ;
F_20 ( 10 ) ;
V_26 = V_36 + F_21 ( V_37 ) ;
do {
if ( F_22 ( V_36 , V_26 ) ) {
F_2 ( L_7 ) ;
return - V_38 ;
}
V_25 = F_23 ( V_2 , V_39 ) ;
} while ( V_25 & 0x3 );
F_19 ( V_2 , 0x0 , V_35 ) ;
F_19 ( V_2 , 0x3fe , V_35 ) ;
}
F_14 () ;
return 0 ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 ) ) {
F_19 ( V_2 , V_2 -> V_12 , V_40 ) ;
F_25 ( 2 , L_8 , V_2 -> V_12 ) ;
} else {
F_19 ( V_2 , V_2 -> V_12 , V_41 ) ;
F_19 ( V_2 , V_2 -> V_16 , V_42 ) ;
F_25 ( 2 , L_9 ,
V_2 -> V_12 , V_2 -> V_16 ) ;
}
}
static inline void F_26 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 ) ) {
} else {
F_19 ( V_2 , 0xffffffff , V_43 ) ;
F_19 ( V_2 , 0xffffffff , V_44 ) ;
F_19 ( V_2 , 0 , V_45 ) ;
F_19 ( V_2 , 0 , V_46 ) ;
}
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_47 ;
int V_48 ;
F_10 () ;
if ( ! V_2 -> V_9 ) {
F_2 ( L_10 ) ;
return - V_22 ;
}
F_25 ( 2 , L_11 ) ;
F_28 () ;
V_48 = F_17 ( V_2 ) ;
if ( V_48 ) {
F_2 ( L_12 ) ;
return V_48 ;
}
F_25 ( 2 , L_13 ) ;
F_24 ( V_2 ) ;
F_26 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( F_18 ( V_2 ) )
F_19 ( V_2 , 0x1 , V_34 ) ;
else
F_19 ( V_2 , 0x3ff , V_35 ) ;
F_25 ( 2 , L_14 ) ;
if ( F_30 ( V_2 , V_49 ) ) {
F_2 ( L_15 ) ;
F_17 ( V_2 ) ;
F_31 () ;
return - V_38 ;
}
F_29 ( V_2 ) ;
V_48 = F_32 ( V_2 -> V_50 , V_51 , V_2 ) ;
if ( V_48 ) {
F_2 ( L_16 ) ;
F_17 ( V_2 ) ;
F_31 () ;
return V_48 ;
}
F_25 ( 2 , L_17 ) ;
if ( F_30 ( V_2 , V_52 ) ) {
F_2 ( L_15 ) ;
F_17 ( V_2 ) ;
F_31 () ;
return - V_38 ;
}
V_2 -> V_53 = 0 ;
if ( V_2 -> V_54 != 0 || V_2 -> V_55 !=
V_52 ) {
F_2 ( L_18 ,
V_2 -> V_54 , V_2 -> V_55 ) ;
F_17 ( V_2 ) ;
F_31 () ;
return - V_38 ;
}
if ( F_18 ( V_2 ) )
V_47 = F_23 ( V_2 , V_31 ) ;
else
V_47 = F_23 ( V_2 , V_56 ) ;
F_25 ( 2 , L_19 ,
( V_47 >> 16 ) & 0xFF , ( V_47 >> 8 ) & 0xFF , V_47 & 0xFF ) ;
F_31 () ;
F_14 () ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
F_28 () ;
F_17 ( V_2 ) ;
F_32 ( V_2 -> V_57 , V_58 , V_2 ) ;
F_31 () ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_48 ;
F_10 () ;
F_28 () ;
F_29 ( V_2 ) ;
V_48 = F_32 ( V_2 -> V_50 , V_59 , V_2 ) ;
if ( V_48 ) {
F_2 ( L_16 ) ;
return V_48 ;
}
if ( F_30 ( V_2 , V_60 ) ) {
F_2 ( L_20 ) ;
return - V_38 ;
}
F_31 () ;
V_2 -> V_53 = 0 ;
if ( V_2 -> V_54 != 0 || V_2 -> V_55 !=
V_60 ) {
F_2 ( L_21 , V_2 -> V_54 ,
V_2 -> V_55 ) ;
return - V_38 ;
}
F_14 () ;
return V_48 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_48 ;
F_10 () ;
F_25 ( 2 , L_11 ) ;
F_28 () ;
V_48 = F_17 ( V_2 ) ;
if ( V_48 ) {
F_2 ( L_12 ) ;
return V_48 ;
}
F_25 ( 2 , L_13 ) ;
F_24 ( V_2 ) ;
F_26 ( V_2 ) ;
F_29 ( V_2 ) ;
V_48 = F_32 ( V_2 -> V_50 , V_61 , V_2 ) ;
if ( V_48 ) {
F_2 ( L_16 ) ;
return V_48 ;
}
if ( F_18 ( V_2 ) )
F_19 ( V_2 , 0x1 , V_34 ) ;
else
F_19 ( V_2 , 0x3ff , V_35 ) ;
F_25 ( 2 , L_22 ) ;
if ( F_30 ( V_2 , V_62 ) ) {
F_2 ( L_15 ) ;
return - V_38 ;
}
F_31 () ;
V_2 -> V_53 = 0 ;
if ( V_2 -> V_54 != 0 || V_2 -> V_55 !=
V_62 ) {
F_2 ( L_23 , V_2 -> V_54 ,
V_2 -> V_55 ) ;
return - V_38 ;
}
F_14 () ;
return 0 ;
}
