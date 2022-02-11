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
if ( ! V_2 -> V_9 ) {
F_2 ( L_2 ) ;
return - V_10 ;
}
if ( F_4 ( V_2 ) && F_5 ( V_2 ) ) {
V_3 = F_3 ( V_2 -> V_14 , 1 << V_15 ,
& V_4 , V_13 ) ;
if ( ! V_3 ) {
F_2 ( L_3 ) ;
F_6 ( V_2 -> V_11 , V_2 -> V_5 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
V_2 -> V_9 = NULL ;
return - V_10 ;
}
V_2 -> V_16 = V_4 - ( 1 << V_15 ) ;
F_6 ( V_2 -> V_14 , 1 << V_15 ,
V_3 , V_4 ) ;
} else {
V_2 -> V_16 = V_2 -> V_12 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_19 , V_20 = - V_21 ;
F_8 () ;
for ( V_19 = V_22 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( ! V_2 -> V_6 -> V_23 [ V_19 ] )
continue;
V_20 = F_9 ( ( const struct V_17 * * ) & V_18 ,
V_2 -> V_6 -> V_23 [ V_19 ] , V_2 -> V_24 . V_2 ) ;
if ( ! V_20 ) {
V_2 -> V_25 = (enum V_26 ) V_19 ;
break;
}
}
if ( V_20 != 0 ) {
F_2 ( L_4 ) ;
return - V_21 ;
}
if ( V_18 -> V_27 > V_2 -> V_5 ) {
F_2 ( L_5 ) ;
F_10 ( V_18 ) ;
return - V_10 ;
}
if ( ! V_2 -> V_9 ) {
F_2 ( L_6 ) ;
F_10 ( V_18 ) ;
return - V_21 ;
}
memcpy ( V_2 -> V_9 , V_18 -> V_28 , V_18 -> V_27 ) ;
F_11 () ;
F_10 ( V_18 ) ;
F_12 () ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 )
return - V_21 ;
F_6 ( V_2 -> V_11 , V_2 -> V_5 , V_2 -> V_9 ,
V_2 -> V_12 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
unsigned long V_30 ;
F_15 ( V_2 , 0x1 , V_31 ) ;
V_30 = V_32 + F_16 ( V_33 ) ;
do {
if ( F_17 ( V_32 , V_30 ) ) {
F_2 ( L_7 ) ;
return - V_34 ;
}
V_29 = F_18 ( V_2 , V_31 ) ;
} while ( ( V_29 & 0x2 ) == 0 );
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
unsigned int V_35 ;
unsigned long V_30 ;
int V_19 ;
F_8 () ;
if ( F_20 ( V_2 ) ) {
F_15 ( V_2 , 0 , V_36 ) ;
F_15 ( V_2 , 0 , V_37 ) ;
F_15 ( V_2 , 0 , V_38 ) ;
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ )
F_15 ( V_2 , 0 , V_40 + ( V_19 * 4 ) ) ;
if ( V_2 -> V_41 )
if ( F_14 ( V_2 ) )
return - V_34 ;
if ( ( ! V_2 -> V_41 ) || ( ! F_21 ( V_2 ) ) )
F_15 ( V_2 , 0 , V_42 ) ;
F_15 ( V_2 , 0x1FFF , V_43 ) ;
F_15 ( V_2 , 0 , V_43 ) ;
} else {
F_15 ( V_2 , 0x3f6 , V_44 ) ;
F_15 ( V_2 , 0x3e2 , V_44 ) ;
F_22 ( 10 ) ;
V_30 = V_32 + F_16 ( V_33 ) ;
do {
if ( F_17 ( V_32 , V_30 ) ) {
F_2 ( L_8 ) ;
return - V_34 ;
}
V_35 = F_18 ( V_2 , V_45 ) ;
} while ( V_35 & 0x3 );
F_15 ( V_2 , 0x0 , V_44 ) ;
F_15 ( V_2 , 0x3fe , V_44 ) ;
}
F_12 () ;
return 0 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( F_20 ( V_2 ) ) {
F_15 ( V_2 , V_2 -> V_12 , V_46 ) ;
F_24 ( 2 , L_9 , & V_2 -> V_12 ) ;
} else {
F_15 ( V_2 , V_2 -> V_12 , V_47 ) ;
F_15 ( V_2 , V_2 -> V_16 , V_48 ) ;
F_24 ( 2 , L_10 ,
& V_2 -> V_12 , & V_2 -> V_16 ) ;
}
}
static inline void F_25 ( struct V_1 * V_2 )
{
if ( F_20 ( V_2 ) ) {
} else {
F_15 ( V_2 , 0xffffffff , V_49 ) ;
F_15 ( V_2 , 0xffffffff , V_50 ) ;
F_15 ( V_2 , 0 , V_51 ) ;
F_15 ( V_2 , 0 , V_52 ) ;
}
}
int F_26 ( struct V_1 * V_2 )
{
unsigned int V_53 ;
int V_54 ;
F_8 () ;
if ( ! V_2 -> V_9 ) {
F_2 ( L_11 ) ;
return - V_21 ;
}
F_24 ( 2 , L_12 ) ;
F_27 () ;
V_2 -> V_41 = 0 ;
V_54 = F_19 ( V_2 ) ;
if ( V_54 ) {
F_2 ( L_13 ) ;
return V_54 ;
}
F_24 ( 2 , L_14 ) ;
F_23 ( V_2 ) ;
F_25 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( F_20 ( V_2 ) ) {
V_2 -> V_41 = 1 ;
F_15 ( V_2 , 0x1 , V_42 ) ;
}
else
F_15 ( V_2 , 0x3ff , V_44 ) ;
F_24 ( 2 , L_15 ) ;
if ( F_29 ( V_2 , V_55 ) ) {
F_2 ( L_16 ) ;
F_19 ( V_2 ) ;
F_30 () ;
return - V_34 ;
}
F_28 ( V_2 ) ;
V_54 = F_31 ( V_2 -> V_56 , V_57 , V_2 ) ;
if ( V_54 ) {
F_2 ( L_17 ) ;
F_19 ( V_2 ) ;
F_30 () ;
return V_54 ;
}
F_24 ( 2 , L_18 ) ;
if ( F_29 ( V_2 , V_58 ) ) {
F_2 ( L_19 ) ;
F_19 ( V_2 ) ;
F_30 () ;
return - V_34 ;
}
V_2 -> V_59 = 0 ;
if ( V_2 -> V_60 != 0 || V_2 -> V_61 !=
V_58 ) {
F_2 ( L_20 ,
V_2 -> V_60 , V_2 -> V_61 ) ;
F_19 ( V_2 ) ;
F_30 () ;
return - V_34 ;
}
if ( F_20 ( V_2 ) )
V_53 = F_18 ( V_2 , V_38 ) ;
else
V_53 = F_18 ( V_2 , V_62 ) ;
F_24 ( 2 , L_21 ,
( V_53 >> 16 ) & 0xFF , ( V_53 >> 8 ) & 0xFF , V_53 & 0xFF ) ;
F_30 () ;
F_12 () ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_27 () ;
F_19 ( V_2 ) ;
F_33 ( V_2 -> V_63 , V_64 , V_2 ) ;
F_30 () ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_54 ;
F_8 () ;
F_27 () ;
F_28 ( V_2 ) ;
V_54 = F_31 ( V_2 -> V_56 , V_65 , V_2 ) ;
if ( V_54 ) {
F_2 ( L_17 ) ;
return V_54 ;
}
if ( F_29 ( V_2 , V_66 ) ) {
F_2 ( L_22 ) ;
return - V_34 ;
}
F_30 () ;
V_2 -> V_59 = 0 ;
if ( V_2 -> V_60 != 0 || V_2 -> V_61 !=
V_66 ) {
F_2 ( L_23 , V_2 -> V_60 ,
V_2 -> V_61 ) ;
return - V_34 ;
}
F_12 () ;
return V_54 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_54 ;
V_2 -> V_41 = 1 ;
F_15 ( V_2 , 0x1 , V_42 ) ;
if ( F_29 ( V_2 , V_55 ) ) {
F_2 ( L_24 ) ;
return - V_34 ;
}
F_24 ( 2 , L_25 ) ;
V_54 = F_31 ( V_2 -> V_56 , V_67 , V_2 ) ;
if ( V_54 ) {
F_2 ( L_26 ) ;
return V_54 ;
}
if ( F_29 ( V_2 , V_68 ) ) {
F_2 ( L_27 ) ;
return - V_34 ;
}
return V_54 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_31 ( V_2 -> V_56 , V_67 , V_2 ) ;
if ( V_54 ) {
F_2 ( L_17 ) ;
return V_54 ;
}
if ( F_20 ( V_2 ) ) {
V_2 -> V_41 = 1 ;
F_15 ( V_2 , 0x1 , V_42 ) ;
} else {
F_15 ( V_2 , 0x3ff , V_44 ) ;
}
if ( F_29 ( V_2 , V_68 ) ) {
F_2 ( L_27 ) ;
return - V_34 ;
}
return V_54 ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_54 ;
F_8 () ;
F_24 ( 2 , L_12 ) ;
F_27 () ;
V_2 -> V_41 = 0 ;
V_54 = F_19 ( V_2 ) ;
if ( V_54 ) {
F_2 ( L_13 ) ;
F_30 () ;
return V_54 ;
}
F_24 ( 2 , L_14 ) ;
F_23 ( V_2 ) ;
F_25 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( F_38 ( V_2 ) )
V_54 = F_35 ( V_2 ) ;
else
V_54 = F_36 ( V_2 ) ;
F_30 () ;
if ( V_54 )
return V_54 ;
V_2 -> V_59 = 0 ;
if ( V_2 -> V_60 != 0 || V_2 -> V_61 !=
V_68 ) {
F_2 ( L_28 , V_2 -> V_60 ,
V_2 -> V_61 ) ;
return - V_34 ;
}
F_12 () ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
int V_54 = 0 ;
V_54 = F_31 ( V_2 -> V_63 , V_71 , V_70 ) ;
if ( V_54 ) {
F_2 ( L_29 ) ;
goto V_20;
}
if ( V_70 -> type == V_72 ) {
V_54 = F_31 ( V_2 -> V_63 ,
V_73 , V_70 ) ;
if ( V_54 ) {
F_2 ( L_30 ) ;
goto V_74;
}
}
F_40 ( V_70 ) ;
F_33 ( V_2 -> V_63 , V_75 , V_2 ) ;
if ( F_41 ( V_70 ,
V_76 , 0 ) ) {
F_2 ( L_31 ) ;
V_54 = - V_34 ;
goto V_77;
}
F_24 ( 2 , L_32 , V_70 -> V_78 ) ;
return V_54 ;
V_77:
if ( V_70 -> type == V_72 )
F_33 ( V_2 -> V_63 , V_79 , V_70 ) ;
V_74:
F_33 ( V_2 -> V_63 , V_80 , V_70 ) ;
V_20:
return V_54 ;
}
void F_42 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
V_70 -> V_81 = V_82 ;
F_40 ( V_70 ) ;
F_33 ( V_2 -> V_63 , V_75 , V_2 ) ;
if ( F_41 ( V_70 ,
V_83 , 0 ) )
F_2 ( L_33 ) ;
F_33 ( V_2 -> V_63 , V_84 , V_70 ) ;
F_33 ( V_2 -> V_63 , V_80 , V_70 ) ;
if ( V_70 -> type == V_72 )
F_33 ( V_2 -> V_63 , V_79 , V_70 ) ;
V_70 -> V_78 = V_85 ;
V_70 -> V_81 = V_86 ;
}
