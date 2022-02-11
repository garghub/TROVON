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
int F_14 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
unsigned long V_30 ;
int V_19 ;
F_8 () ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 , 0xFEE , V_31 ) ;
F_16 ( V_2 , 0x0 , V_31 ) ;
F_16 ( V_2 , 0 , V_32 ) ;
F_16 ( V_2 , 0 , V_33 ) ;
F_16 ( V_2 , 0 , V_34 ) ;
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ )
F_16 ( V_2 , 0 , V_36 + ( V_19 * 4 ) ) ;
F_16 ( V_2 , 0 , V_37 ) ;
F_16 ( V_2 , 0x1FFF , V_31 ) ;
F_16 ( V_2 , 0 , V_31 ) ;
} else {
F_16 ( V_2 , 0x3f6 , V_38 ) ;
F_16 ( V_2 , 0x3e2 , V_38 ) ;
F_17 ( 10 ) ;
V_30 = V_39 + F_18 ( V_40 ) ;
do {
if ( F_19 ( V_39 , V_30 ) ) {
F_2 ( L_7 ) ;
return - V_41 ;
}
V_29 = F_20 ( V_2 , V_42 ) ;
} while ( V_29 & 0x3 );
F_16 ( V_2 , 0x0 , V_38 ) ;
F_16 ( V_2 , 0x3fe , V_38 ) ;
}
F_12 () ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 , V_2 -> V_12 , V_43 ) ;
F_22 ( 2 , L_8 , V_2 -> V_12 ) ;
} else {
F_16 ( V_2 , V_2 -> V_12 , V_44 ) ;
F_16 ( V_2 , V_2 -> V_16 , V_45 ) ;
F_22 ( 2 , L_9 ,
V_2 -> V_12 , V_2 -> V_16 ) ;
}
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) ) {
} else {
F_16 ( V_2 , 0xffffffff , V_46 ) ;
F_16 ( V_2 , 0xffffffff , V_47 ) ;
F_16 ( V_2 , 0 , V_48 ) ;
F_16 ( V_2 , 0 , V_49 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
int V_51 ;
F_8 () ;
if ( ! V_2 -> V_9 ) {
F_2 ( L_10 ) ;
return - V_21 ;
}
F_22 ( 2 , L_11 ) ;
F_25 () ;
V_51 = F_14 ( V_2 ) ;
if ( V_51 ) {
F_2 ( L_12 ) ;
return V_51 ;
}
F_22 ( 2 , L_13 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( F_15 ( V_2 ) )
F_16 ( V_2 , 0x1 , V_37 ) ;
else
F_16 ( V_2 , 0x3ff , V_38 ) ;
F_22 ( 2 , L_14 ) ;
if ( F_27 ( V_2 , V_52 ) ) {
F_2 ( L_15 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return - V_41 ;
}
F_26 ( V_2 ) ;
V_51 = F_29 ( V_2 -> V_53 , V_54 , V_2 ) ;
if ( V_51 ) {
F_2 ( L_16 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return V_51 ;
}
F_22 ( 2 , L_17 ) ;
if ( F_27 ( V_2 , V_55 ) ) {
F_2 ( L_15 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return - V_41 ;
}
V_2 -> V_56 = 0 ;
if ( V_2 -> V_57 != 0 || V_2 -> V_58 !=
V_55 ) {
F_2 ( L_18 ,
V_2 -> V_57 , V_2 -> V_58 ) ;
F_14 ( V_2 ) ;
F_28 () ;
return - V_41 ;
}
if ( F_15 ( V_2 ) )
V_50 = F_20 ( V_2 , V_34 ) ;
else
V_50 = F_20 ( V_2 , V_59 ) ;
F_22 ( 2 , L_19 ,
( V_50 >> 16 ) & 0xFF , ( V_50 >> 8 ) & 0xFF , V_50 & 0xFF ) ;
F_28 () ;
F_12 () ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_25 () ;
F_14 ( V_2 ) ;
F_29 ( V_2 -> V_60 , V_61 , V_2 ) ;
F_28 () ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_51 ;
F_8 () ;
F_25 () ;
F_26 ( V_2 ) ;
V_51 = F_29 ( V_2 -> V_53 , V_62 , V_2 ) ;
if ( V_51 ) {
F_2 ( L_16 ) ;
return V_51 ;
}
if ( F_27 ( V_2 , V_63 ) ) {
F_2 ( L_20 ) ;
return - V_41 ;
}
F_28 () ;
V_2 -> V_56 = 0 ;
if ( V_2 -> V_57 != 0 || V_2 -> V_58 !=
V_63 ) {
F_2 ( L_21 , V_2 -> V_57 ,
V_2 -> V_58 ) ;
return - V_41 ;
}
F_12 () ;
return V_51 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_51 ;
F_8 () ;
F_22 ( 2 , L_11 ) ;
F_25 () ;
V_51 = F_14 ( V_2 ) ;
if ( V_51 ) {
F_2 ( L_12 ) ;
return V_51 ;
}
F_22 ( 2 , L_13 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
V_51 = F_29 ( V_2 -> V_53 , V_64 , V_2 ) ;
if ( V_51 ) {
F_2 ( L_16 ) ;
return V_51 ;
}
if ( F_15 ( V_2 ) )
F_16 ( V_2 , 0x1 , V_37 ) ;
else
F_16 ( V_2 , 0x3ff , V_38 ) ;
F_22 ( 2 , L_22 ) ;
if ( F_27 ( V_2 , V_65 ) ) {
F_2 ( L_15 ) ;
return - V_41 ;
}
F_28 () ;
V_2 -> V_56 = 0 ;
if ( V_2 -> V_57 != 0 || V_2 -> V_58 !=
V_65 ) {
F_2 ( L_23 , V_2 -> V_57 ,
V_2 -> V_58 ) ;
return - V_41 ;
}
F_12 () ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_51 = 0 ;
V_51 = F_29 ( V_2 -> V_60 , V_68 , V_67 ) ;
if ( V_51 ) {
F_2 ( L_24 ) ;
goto V_20;
}
if ( V_67 -> type == V_69 ) {
V_51 = F_29 ( V_2 -> V_60 ,
V_70 , V_67 ) ;
if ( V_51 ) {
F_2 ( L_25 ) ;
goto V_71;
}
}
F_34 ( V_67 ) ;
F_35 ( V_67 ) ;
F_29 ( V_2 -> V_60 , V_72 , V_2 ) ;
if ( F_36 ( V_67 ,
V_73 , 0 ) ) {
F_2 ( L_26 ) ;
V_51 = - V_41 ;
goto V_74;
}
F_22 ( 2 , L_27 , V_67 -> V_75 ) ;
return V_51 ;
V_74:
if ( V_67 -> type == V_69 )
F_29 ( V_2 -> V_60 , V_76 , V_67 ) ;
V_71:
F_29 ( V_2 -> V_60 , V_77 , V_67 ) ;
V_20:
return V_51 ;
}
void F_37 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
V_67 -> V_78 = V_79 ;
F_34 ( V_67 ) ;
F_35 ( V_67 ) ;
F_29 ( V_2 -> V_60 , V_72 , V_2 ) ;
if ( F_36 ( V_67 ,
V_80 , 0 ) )
F_2 ( L_28 ) ;
F_29 ( V_2 -> V_60 , V_81 , V_67 ) ;
F_29 ( V_2 -> V_60 , V_77 , V_67 ) ;
if ( V_67 -> type == V_69 )
F_29 ( V_2 -> V_60 , V_76 , V_67 ) ;
V_67 -> V_75 = V_82 ;
V_67 -> V_78 = V_83 ;
}
