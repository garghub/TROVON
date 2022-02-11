int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
V_4 -> V_6 = V_2 -> V_7 -> V_8 -> V_9 ;
if ( V_4 -> V_10 ) {
F_2 ( L_1 ) ;
return - V_11 ;
}
V_5 = F_3 ( V_2 , V_12 , & V_2 -> V_4 ) ;
if ( V_5 ) {
F_2 ( L_2 ) ;
return V_5 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_15 , V_5 = - V_16 ;
F_5 () ;
for ( V_15 = V_17 - 1 ; V_15 >= 0 ; V_15 -- ) {
if ( ! V_2 -> V_7 -> V_18 [ V_15 ] )
continue;
V_5 = F_6 ( ( const struct V_13 * * ) & V_14 ,
V_2 -> V_7 -> V_18 [ V_15 ] , V_2 -> V_19 . V_2 ) ;
if ( ! V_5 ) {
V_2 -> V_20 = (enum V_21 ) V_15 ;
break;
}
}
if ( V_5 != 0 ) {
F_2 ( L_3 ) ;
return - V_16 ;
}
if ( V_14 -> V_6 > V_2 -> V_4 . V_6 ) {
F_2 ( L_4 ) ;
F_7 ( V_14 ) ;
return - V_11 ;
}
if ( ! V_2 -> V_4 . V_10 ) {
F_2 ( L_5 ) ;
F_7 ( V_14 ) ;
return - V_16 ;
}
memcpy ( V_2 -> V_4 . V_10 , V_14 -> V_22 , V_14 -> V_6 ) ;
F_8 () ;
F_7 ( V_14 ) ;
F_9 () ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 , & V_2 -> V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
unsigned long V_24 ;
F_13 ( V_2 , 0x1 , V_25 ) ;
V_24 = V_26 + F_14 ( V_27 ) ;
do {
if ( F_15 ( V_26 , V_24 ) ) {
F_2 ( L_6 ) ;
return - V_28 ;
}
V_23 = F_16 ( V_2 , V_25 ) ;
} while ( ( V_23 & 0x2 ) == 0 );
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
unsigned long V_24 ;
int V_15 ;
F_5 () ;
if ( F_18 ( V_2 ) ) {
F_13 ( V_2 , 0 , V_30 ) ;
F_13 ( V_2 , 0 , V_31 ) ;
F_13 ( V_2 , 0 , V_32 ) ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ )
F_13 ( V_2 , 0 , V_34 + ( V_15 * 4 ) ) ;
if ( V_2 -> V_35 )
if ( F_12 ( V_2 ) )
return - V_28 ;
if ( ( ! V_2 -> V_35 ) || ( ! F_19 ( V_2 ) ) )
F_13 ( V_2 , 0 , V_36 ) ;
F_13 ( V_2 , 0x1FFF , V_37 ) ;
F_13 ( V_2 , 0 , V_37 ) ;
} else {
F_13 ( V_2 , 0x3f6 , V_38 ) ;
F_13 ( V_2 , 0x3e2 , V_38 ) ;
F_20 ( 10 ) ;
V_24 = V_26 + F_14 ( V_27 ) ;
do {
if ( F_15 ( V_26 , V_24 ) ) {
F_2 ( L_7 ) ;
return - V_28 ;
}
V_29 = F_16 ( V_2 , V_39 ) ;
} while ( V_29 & 0x3 );
F_13 ( V_2 , 0x0 , V_38 ) ;
F_13 ( V_2 , 0x3fe , V_38 ) ;
}
F_9 () ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 ) ) {
F_13 ( V_2 , V_2 -> V_40 [ V_12 ] ,
V_41 ) ;
F_22 ( 2 , L_8 ,
& V_2 -> V_40 [ V_12 ] ) ;
} else {
F_13 ( V_2 , V_2 -> V_40 [ V_12 ] ,
V_42 ) ;
F_13 ( V_2 , V_2 -> V_40 [ V_43 ] ,
V_44 ) ;
F_22 ( 2 , L_9 ,
& V_2 -> V_40 [ V_12 ] ,
& V_2 -> V_40 [ V_43 ] ) ;
}
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 ) ) {
} else {
F_13 ( V_2 , 0xffffffff , V_45 ) ;
F_13 ( V_2 , 0xffffffff , V_46 ) ;
F_13 ( V_2 , 0 , V_47 ) ;
F_13 ( V_2 , 0 , V_48 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
unsigned int V_49 ;
int V_50 ;
F_5 () ;
if ( ! V_2 -> V_4 . V_10 ) {
F_2 ( L_10 ) ;
return - V_16 ;
}
F_22 ( 2 , L_11 ) ;
F_25 () ;
V_2 -> V_35 = 0 ;
V_50 = F_17 ( V_2 ) ;
if ( V_50 ) {
F_2 ( L_12 ) ;
return V_50 ;
}
F_22 ( 2 , L_13 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
V_2 -> V_35 = 1 ;
F_13 ( V_2 , 0x1 , V_36 ) ;
}
else
F_13 ( V_2 , 0x3ff , V_38 ) ;
F_22 ( 2 , L_14 ) ;
if ( F_27 ( V_2 , V_51 ) ) {
F_2 ( L_15 ) ;
F_17 ( V_2 ) ;
F_28 () ;
return - V_28 ;
}
F_26 ( V_2 ) ;
V_50 = F_29 ( V_2 -> V_52 , V_53 , V_2 ) ;
if ( V_50 ) {
F_2 ( L_16 ) ;
F_17 ( V_2 ) ;
F_28 () ;
return V_50 ;
}
F_22 ( 2 , L_17 ) ;
if ( F_27 ( V_2 , V_54 ) ) {
F_2 ( L_18 ) ;
F_17 ( V_2 ) ;
F_28 () ;
return - V_28 ;
}
V_2 -> V_55 = 0 ;
if ( V_2 -> V_56 != 0 || V_2 -> V_57 !=
V_54 ) {
F_2 ( L_19 ,
V_2 -> V_56 , V_2 -> V_57 ) ;
F_17 ( V_2 ) ;
F_28 () ;
return - V_28 ;
}
if ( F_18 ( V_2 ) )
V_49 = F_16 ( V_2 , V_32 ) ;
else
V_49 = F_16 ( V_2 , V_58 ) ;
F_22 ( 2 , L_20 ,
( V_49 >> 16 ) & 0xFF , ( V_49 >> 8 ) & 0xFF , V_49 & 0xFF ) ;
F_28 () ;
F_9 () ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_25 () ;
F_17 ( V_2 ) ;
F_29 ( V_2 -> V_59 , V_60 , V_2 ) ;
F_28 () ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_50 ;
F_5 () ;
F_25 () ;
F_26 ( V_2 ) ;
V_50 = F_29 ( V_2 -> V_52 , V_61 , V_2 ) ;
if ( V_50 ) {
F_2 ( L_16 ) ;
return V_50 ;
}
if ( F_27 ( V_2 , V_62 ) ) {
F_2 ( L_21 ) ;
return - V_28 ;
}
F_28 () ;
V_2 -> V_55 = 0 ;
if ( V_2 -> V_56 != 0 || V_2 -> V_57 !=
V_62 ) {
F_2 ( L_22 , V_2 -> V_56 ,
V_2 -> V_57 ) ;
return - V_28 ;
}
F_9 () ;
return V_50 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_50 ;
V_2 -> V_35 = 1 ;
F_13 ( V_2 , 0x1 , V_36 ) ;
if ( F_27 ( V_2 , V_51 ) ) {
F_2 ( L_23 ) ;
return - V_28 ;
}
F_22 ( 2 , L_24 ) ;
V_50 = F_29 ( V_2 -> V_52 , V_63 , V_2 ) ;
if ( V_50 ) {
F_2 ( L_25 ) ;
return V_50 ;
}
if ( F_27 ( V_2 , V_64 ) ) {
F_2 ( L_26 ) ;
return - V_28 ;
}
return V_50 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_29 ( V_2 -> V_52 , V_63 , V_2 ) ;
if ( V_50 ) {
F_2 ( L_16 ) ;
return V_50 ;
}
if ( F_18 ( V_2 ) ) {
V_2 -> V_35 = 1 ;
F_13 ( V_2 , 0x1 , V_36 ) ;
} else {
F_13 ( V_2 , 0x3ff , V_38 ) ;
}
if ( F_27 ( V_2 , V_64 ) ) {
F_2 ( L_26 ) ;
return - V_28 ;
}
return V_50 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_50 ;
F_5 () ;
F_22 ( 2 , L_11 ) ;
F_25 () ;
V_2 -> V_35 = 0 ;
V_50 = F_17 ( V_2 ) ;
if ( V_50 ) {
F_2 ( L_12 ) ;
F_28 () ;
return V_50 ;
}
F_22 ( 2 , L_13 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( F_35 ( V_2 ) )
V_50 = F_32 ( V_2 ) ;
else
V_50 = F_33 ( V_2 ) ;
F_28 () ;
if ( V_50 )
return V_50 ;
V_2 -> V_55 = 0 ;
if ( V_2 -> V_56 != 0 || V_2 -> V_57 !=
V_64 ) {
F_2 ( L_27 , V_2 -> V_56 ,
V_2 -> V_57 ) ;
return - V_28 ;
}
F_9 () ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
int V_50 = 0 ;
V_50 = F_29 ( V_2 -> V_59 , V_67 , V_66 ) ;
if ( V_50 ) {
F_2 ( L_28 ) ;
goto V_5;
}
if ( V_66 -> type == V_68 ) {
V_50 = F_29 ( V_2 -> V_59 ,
V_69 , V_66 ) ;
if ( V_50 ) {
F_2 ( L_29 ) ;
goto V_70;
}
}
F_37 ( V_66 ) ;
F_29 ( V_2 -> V_59 , V_71 , V_2 ) ;
if ( F_38 ( V_66 ,
V_72 , 0 ) ) {
F_2 ( L_30 ) ;
V_50 = - V_28 ;
goto V_73;
}
F_22 ( 2 , L_31 , V_66 -> V_74 ) ;
return V_50 ;
V_73:
if ( V_66 -> type == V_68 )
F_29 ( V_2 -> V_59 , V_75 , V_66 ) ;
V_70:
F_29 ( V_2 -> V_59 , V_76 , V_66 ) ;
V_5:
return V_50 ;
}
void F_39 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
V_66 -> V_77 = V_78 ;
F_37 ( V_66 ) ;
F_29 ( V_2 -> V_59 , V_71 , V_2 ) ;
if ( F_38 ( V_66 ,
V_79 , 0 ) )
F_2 ( L_32 ) ;
F_29 ( V_2 -> V_59 , V_80 , V_66 ) ;
F_29 ( V_2 -> V_59 , V_76 , V_66 ) ;
if ( V_66 -> type == V_68 )
F_29 ( V_2 -> V_59 , V_75 , V_66 ) ;
V_66 -> V_74 = V_81 ;
V_66 -> V_77 = V_82 ;
}
