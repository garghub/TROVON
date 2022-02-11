static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_5 , int type , char * V_6 )
{
struct V_1 * V_7 , * V_8 ;
V_8 = type & V_9 ? & V_10 : & V_11 ;
V_7 = F_2 ( V_4 , V_5 , type | V_12 , V_6 ) ;
if ( V_7 ) {
#ifdef F_3
if ( V_3 && V_3 -> V_13 )
V_8 = F_4 ( V_3 -> V_13 , V_7 ) ;
#endif
if ( ! V_8 || F_5 ( V_8 , V_7 ) ) {
F_6 ( V_7 ) ;
V_7 = NULL ;
}
}
return V_7 ;
}
static void F_7 ( struct V_1 * V_7 )
{
if ( V_7 ) {
F_8 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static int F_9 ( struct V_14 * V_15 , T_2 V_4 , T_2 V_16 )
{
struct V_14 * V_17 , * V_18 ;
for ( V_17 = V_15 ; ; V_17 = V_17 -> V_19 ) {
if ( ( V_17 != V_15 ) && ( V_17 -> V_4 + V_17 -> V_16 >= V_4 ) ) {
V_17 -> V_16 = F_10 ( V_16 + V_4 - V_17 -> V_4 , V_17 -> V_16 ) ;
return 0 ;
}
if ( ( V_17 -> V_19 == V_15 ) || ( V_17 -> V_19 -> V_4 > V_4 + V_16 - 1 ) )
break;
}
V_18 = F_11 ( sizeof( struct V_14 ) , V_20 ) ;
if ( ! V_18 ) {
F_12 ( V_21 L_1 ) ;
return - V_22 ;
}
V_18 -> V_4 = V_4 ; V_18 -> V_16 = V_16 ;
V_18 -> V_19 = V_17 -> V_19 ; V_17 -> V_19 = V_18 ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , T_2 V_4 , T_2 V_16 )
{
struct V_14 * V_17 , * V_18 ;
for ( V_17 = V_15 ; ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
if ( V_18 == V_15 )
break;
if ( ( V_18 -> V_4 + V_18 -> V_16 > V_4 ) && ( V_4 + V_16 > V_18 -> V_4 ) ) {
if ( V_18 -> V_4 >= V_4 ) {
if ( V_18 -> V_4 + V_18 -> V_16 <= V_4 + V_16 ) {
V_17 -> V_19 = V_18 -> V_19 ;
F_6 ( V_18 ) ;
V_18 = V_17 ;
} else {
V_18 -> V_16 = V_18 -> V_4 + V_18 -> V_16 - V_4 - V_16 ;
V_18 -> V_4 = V_4 + V_16 ;
}
} else if ( V_18 -> V_4 + V_18 -> V_16 <= V_4 + V_16 ) {
V_18 -> V_16 = V_4 - V_18 -> V_4 ;
} else {
V_17 = F_11 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_17 ) {
F_12 ( V_21 L_1 ) ;
return - V_22 ;
}
V_17 -> V_4 = V_4 + V_16 ;
V_17 -> V_16 = V_18 -> V_4 + V_18 -> V_16 - V_17 -> V_4 ;
V_18 -> V_16 = V_4 - V_18 -> V_4 ;
V_17 -> V_19 = V_18 -> V_19 ; V_18 -> V_19 = V_17 ;
}
}
}
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , unsigned int V_4 ,
unsigned int V_16 )
{
struct V_1 * V_7 ;
struct V_23 * V_24 = V_3 -> V_25 ;
unsigned int V_26 , V_27 , V_28 ;
int V_29 ;
T_3 * V_30 , V_31 , V_32 ;
F_15 ( & V_3 -> V_33 , L_2 , V_4 , V_4 + V_16 - 1 ) ;
V_30 = F_16 ( 256 , V_20 ) ;
if ( ! V_30 ) {
F_17 ( L_3 ) ;
F_18 ( & V_3 -> V_33 , L_4 ) ;
return;
}
for ( V_26 = V_4 , V_32 = 0 ; V_26 < V_4 + V_16 ; V_26 += 8 ) {
V_7 = F_1 ( V_3 , V_26 , 8 , V_34 , L_5 ) ;
if ( ! V_7 )
continue;
V_31 = F_19 ( V_26 ) ;
for ( V_27 = 1 ; V_27 < 8 ; V_27 ++ )
if ( F_19 ( V_26 + V_27 ) != V_31 )
break;
F_7 ( V_7 ) ;
if ( ( V_27 == 8 ) && ( ++ V_30 [ V_31 ] > V_30 [ V_32 ] ) )
V_32 = V_31 ;
if ( V_30 [ V_32 ] == 127 )
break;
}
F_6 ( V_30 ) ;
V_28 = V_29 = 0 ;
for ( V_26 = V_4 ; V_26 < V_4 + V_16 ; V_26 += 8 ) {
V_7 = F_1 ( V_3 , V_26 , 8 , V_34 , L_5 ) ;
if ( ! V_7 ) {
if ( ! V_29 )
F_17 ( L_6 ) ;
if ( ! V_28 )
V_28 = V_29 = V_26 ;
continue;
}
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
if ( F_19 ( V_26 + V_27 ) != V_32 )
break;
F_7 ( V_7 ) ;
if ( V_27 < 8 ) {
if ( ! V_29 )
F_17 ( L_6 ) ;
if ( ! V_28 )
V_28 = V_29 = V_26 ;
} else {
if ( V_28 ) {
F_13 ( & V_24 -> V_35 , V_28 , V_26 - V_28 ) ;
F_17 ( L_7 , V_28 , V_26 - 1 ) ;
V_28 = 0 ;
}
}
}
if ( V_28 ) {
if ( ( V_16 > 16 ) && ( V_28 == V_4 ) && ( V_26 == V_4 + V_16 ) ) {
F_13 ( & V_24 -> V_35 , V_28 , V_26 - V_28 ) ;
F_17 ( L_8 ) ;
return;
} else {
F_13 ( & V_24 -> V_35 , V_28 , V_26 - V_28 ) ;
F_17 ( L_7 , V_28 , V_26 - 1 ) ;
}
}
F_17 ( L_9 , ! V_29 ? L_10 : L_11 ) ;
}
static int F_20 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int * V_36 )
{
int V_37 = - V_38 ;
if ( V_3 -> V_39 ) {
F_21 ( & V_3 -> V_33 , L_12 ) ;
return 0 ;
}
V_3 -> V_40 . V_7 = V_7 ;
V_3 -> V_41 = F_22 ( V_7 -> V_42 , V_3 -> V_43 ) ;
if ( V_3 -> V_41 ) {
F_23 ( & V_3 -> V_44 ) ;
if ( V_3 -> V_45 -> V_46 )
V_37 = V_3 -> V_45 -> V_46 ( V_3 , V_36 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_25 ( V_3 -> V_41 ) ;
V_3 -> V_41 = NULL ;
}
V_3 -> V_40 . V_7 = NULL ;
if ( ( V_37 ) || ( * V_36 == 0 ) )
return - V_38 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int * V_47 )
{
T_4 V_15 ;
int V_26 , V_48 = 0 , V_30 = - 1 , V_49 ;
void T_5 * V_50 ;
V_50 = F_22 ( V_7 -> V_42 , V_3 -> V_43 ) ;
if ( V_50 ) {
V_15 . V_15 = 0 ;
V_15 . V_51 = V_52 ;
V_15 . V_53 = 0 ;
V_15 . V_7 = V_7 ;
V_15 . V_54 = 0 ;
V_3 -> V_55 -> V_56 ( V_3 , & V_15 ) ;
for ( V_26 = 0 ; V_26 < V_3 -> V_43 ; V_26 += 44 ) {
V_49 = F_27 ( V_50 + V_26 ) ;
V_48 += V_49 ;
V_30 &= V_49 ;
}
V_15 . V_51 = 0 ;
V_3 -> V_55 -> V_56 ( V_3 , & V_15 ) ;
F_25 ( V_50 ) ;
}
if ( V_30 == - 1 )
return - V_38 ;
* V_47 = V_48 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
unsigned long V_4 , unsigned long V_5 ,
int V_46 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
unsigned int * V_47 ) )
{
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_57 , * V_58 ;
unsigned int V_59 = 1 , V_60 = 1 ;
int V_37 = - V_38 ;
V_57 = F_1 ( V_3 , V_4 , V_5 / 2 , V_9 , L_13 ) ;
V_58 = F_1 ( V_3 , V_4 + V_5 / 2 , V_5 / 2 , V_9 ,
L_13 ) ;
if ( V_57 && V_58 ) {
V_37 = 0 ;
if ( V_46 ) {
V_37 = V_46 ( V_3 , V_57 , & V_59 ) ;
V_37 += V_46 ( V_3 , V_58 , & V_60 ) ;
}
}
F_21 ( & V_3 -> V_33 , L_14 ,
V_4 , V_4 + V_5 - 1 , V_57 , V_58 , V_37 , V_59 , V_60 ) ;
F_7 ( V_58 ) ;
F_7 ( V_57 ) ;
if ( ( V_37 ) || ( V_59 != V_60 ) || ( V_59 == 0 ) )
return - V_38 ;
if ( V_46 && ! V_3 -> V_39 ) {
F_9 ( & V_24 -> V_61 , V_4 , V_5 ) ;
F_13 ( & V_24 -> V_62 , V_4 , V_5 ) ;
}
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , T_2 V_4 , T_2 V_16 ,
int V_46 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
unsigned int * V_47 ) ,
int F_30 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
unsigned int * V_47 ) )
{
struct V_23 * V_24 = V_3 -> V_25 ;
T_2 V_26 , V_27 , V_28 , V_63 , V_64 ;
F_15 ( & V_3 -> V_33 , L_15 ,
V_4 , V_4 + V_16 - 1 ) ;
V_28 = V_63 = 0 ;
V_64 = ( V_16 < 0x20000 ) ? 0x2000 : ( ( V_16 >> 4 ) & ~ 0x1fff ) ;
if ( V_64 > 0x800000 )
V_64 = 0x800000 ;
if ( V_64 < 2 * V_3 -> V_43 )
V_64 = 2 * V_3 -> V_43 ;
for ( V_26 = V_27 = V_4 ; V_26 < V_4 + V_16 ; V_26 = V_27 + V_64 ) {
if ( ! V_63 ) {
for ( V_27 = V_26 ; V_27 < V_4 + V_16 ; V_27 += V_64 ) {
if ( ! F_28 ( V_3 , V_27 , V_64 , V_46 ) )
break;
}
V_63 = ( ( V_26 == V_4 ) && ( V_27 == V_4 + V_16 ) ) ;
}
if ( ( V_63 ) && ( F_30 ) ) {
for ( V_27 = V_26 ; V_27 < V_4 + V_16 ; V_27 += V_64 )
if ( ! F_28 ( V_3 , V_27 , V_64 , F_30 ) )
break;
}
if ( V_26 != V_27 ) {
if ( ! V_28 )
F_17 ( L_6 ) ;
F_17 ( L_16 , V_26 , V_27 - 1 ) ;
F_13 ( & V_24 -> V_62 , V_26 , V_27 - V_26 ) ;
V_28 += V_27 - V_26 ;
}
}
F_17 ( L_9 , ! V_28 ? L_10 : L_11 ) ;
return V_16 - V_28 ;
}
static T_2 F_31 ( struct V_14 * V_65 , struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
T_2 V_66 ;
if ( V_65 == & V_24 -> V_62 )
return 0 ;
V_66 = F_31 ( V_65 -> V_19 , V_3 ) ;
if ( V_66 ) {
if ( V_65 -> V_4 >= 0x100000 )
F_13 ( & V_24 -> V_62 , V_65 -> V_4 , V_65 -> V_16 ) ;
return V_66 ;
}
if ( V_65 -> V_4 < 0x100000 )
return 0 ;
return F_29 ( V_3 , V_65 -> V_4 , V_65 -> V_16 , F_20 , F_26 ) ;
}
static int F_32 ( struct V_2 * V_3 , unsigned int V_67 )
{
struct V_14 * V_65 , V_68 ;
static unsigned char V_69 [] = { 0xd0 , 0xe0 , 0xc0 , 0xf0 } ;
unsigned long V_30 , V_26 , V_66 = 0 ;
struct V_23 * V_24 = V_3 -> V_25 ;
if ( V_67 & V_70 ) {
if ( F_31 ( V_24 -> V_62 . V_19 , V_3 ) > 0 )
return 0 ;
if ( V_24 -> V_61 . V_19 != & V_24 -> V_61 )
return 0 ;
F_33 ( & V_3 -> V_33 ,
L_17 ) ;
return - V_71 ;
}
for ( V_65 = V_24 -> V_62 . V_19 ; V_65 != & V_24 -> V_62 ; V_65 = V_68 . V_19 ) {
V_68 = * V_65 ;
if ( V_68 . V_4 >= 0x100000 )
continue;
if ( ( V_68 . V_4 | V_68 . V_16 ) & 0xffff ) {
V_66 += F_29 ( V_3 , V_68 . V_4 , V_68 . V_16 , F_20 ,
F_26 ) ;
continue;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_30 = V_69 [ V_26 ] << 12 ;
if ( ( V_30 >= V_68 . V_4 ) && ( V_30 + 0x10000 <= V_68 . V_4 + V_68 . V_16 ) ) {
if ( V_66 >= V_72 )
F_13 ( & V_24 -> V_62 , V_30 , 0x10000 ) ;
else
V_66 += F_29 ( V_3 , V_30 , 0x10000 ,
F_20 , F_26 ) ;
}
}
}
if ( V_66 > 0 )
return 0 ;
return - V_71 ;
}
static int F_32 ( struct V_2 * V_3 , unsigned int V_67 )
{
struct V_14 * V_65 , V_68 ;
struct V_23 * V_24 = V_3 -> V_25 ;
unsigned long V_66 = 0 ;
for ( V_65 = V_24 -> V_62 . V_19 ; V_65 != & V_24 -> V_62 ; V_65 = V_68 . V_19 ) {
V_68 = * V_65 ;
V_66 += F_29 ( V_3 , V_68 . V_4 , V_68 . V_16 , F_20 , F_26 ) ;
}
if ( V_66 > 0 )
return 0 ;
return - V_71 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
unsigned int V_67 = V_73 ;
int V_37 ;
if ( ! V_74 || ! ( V_3 -> V_75 & V_76 ) )
return 0 ;
if ( V_3 -> V_77 & V_78 )
V_67 = V_70 ;
V_37 = F_32 ( V_3 , V_67 ) ;
if ( V_24 -> V_61 . V_19 != & V_24 -> V_61 )
return 0 ;
return V_37 ;
}
static T_1 F_35 ( struct V_79 * V_80 ,
T_1 V_42 )
{
T_1 V_37 ;
V_37 = ( V_42 & ~ V_80 -> V_81 ) + V_80 -> V_82 ;
if ( V_37 < V_42 )
V_37 += V_80 -> V_81 + 1 ;
return V_37 ;
}
static T_1
F_36 ( void * V_80 , const struct V_1 * V_7 ,
T_1 V_5 , T_1 V_83 )
{
struct V_79 * V_84 = V_80 ;
struct V_14 * V_65 ;
T_1 V_42 ;
V_42 = F_35 ( V_84 , V_7 -> V_42 ) ;
for ( V_65 = V_84 -> V_15 -> V_19 ; V_65 != V_84 -> V_15 ; V_65 = V_65 -> V_19 ) {
unsigned long V_85 = V_65 -> V_4 ;
unsigned long V_86 = V_65 -> V_4 + V_65 -> V_16 - 1 ;
if ( V_42 < V_85 )
V_42 = F_35 ( V_84 , V_85 ) ;
if ( V_42 >= V_7 -> V_87 )
break;
if ( ( V_42 + V_5 - 1 ) <= V_86 )
break;
}
if ( V_65 == V_84 -> V_15 )
V_42 = V_7 -> V_87 ;
return V_42 ;
}
static int F_37 ( struct V_2 * V_3 ,
unsigned long V_88 ,
unsigned long V_89 )
{
struct V_14 * V_65 ;
struct V_23 * V_24 = V_3 -> V_25 ;
int V_37 = - V_22 ;
for ( V_65 = V_24 -> V_35 . V_19 ; V_65 != & V_24 -> V_35 ; V_65 = V_65 -> V_19 ) {
unsigned long V_42 = V_65 -> V_4 ;
unsigned long V_87 = V_65 -> V_4 + V_65 -> V_16 - 1 ;
if ( V_42 > V_88 || V_89 > V_87 )
continue;
V_37 = 0 ;
}
return V_37 ;
}
static struct V_1 * F_38 ( struct V_2 * V_3 ,
unsigned long V_4 , int V_16 ,
unsigned long V_83 )
{
struct V_1 * V_7 = F_2 ( 0 , V_16 , V_34 ,
F_39 ( & V_3 -> V_33 ) ) ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_79 V_84 ;
unsigned long V_90 = V_4 ;
int V_37 ;
V_84 . V_81 = V_83 - 1 ;
V_84 . V_82 = V_4 & V_84 . V_81 ;
V_84 . V_15 = & V_24 -> V_35 ;
#ifdef F_3
if ( V_3 -> V_13 ) {
V_37 = F_40 ( V_3 -> V_13 -> V_91 , V_7 , V_16 , 1 ,
V_90 , 0 , F_36 , & V_84 ) ;
} else
#endif
V_37 = F_41 ( & V_11 , V_7 , V_16 , V_90 , ~ 0UL ,
1 , F_36 , & V_84 ) ;
if ( V_37 != 0 ) {
F_6 ( V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
static int F_42 ( struct V_2 * V_3 , unsigned int V_92 ,
unsigned int * V_4 , unsigned int V_16 ,
unsigned int V_83 , struct V_1 * * V_8 )
{
int V_26 , V_37 = 0 ;
for ( V_26 = 0 ; V_26 < V_93 ; V_26 ++ ) {
if ( ! V_3 -> V_94 [ V_26 ] . V_7 )
continue;
if ( ! * V_4 )
continue;
if ( ( V_3 -> V_94 [ V_26 ] . V_7 -> V_42 & ( V_83 - 1 ) ) == * V_4 )
return - V_95 ;
}
for ( V_26 = 0 ; V_26 < V_93 ; V_26 ++ ) {
struct V_1 * V_7 = V_3 -> V_94 [ V_26 ] . V_7 ;
unsigned int V_96 ;
if ( V_7 && ( V_7 -> V_51 & V_97 ) !=
( V_92 & V_97 ) )
continue;
if ( ! V_7 ) {
if ( V_83 == 0 )
V_83 = 0x10000 ;
V_7 = V_3 -> V_94 [ V_26 ] . V_7 = F_38 ( V_3 ,
* V_4 , V_16 ,
V_83 ) ;
if ( ! V_7 )
return - V_38 ;
* V_4 = V_7 -> V_42 ;
V_3 -> V_94 [ V_26 ] . V_7 -> V_51 =
( ( V_7 -> V_51 & ~ V_97 ) |
( V_92 & V_97 ) ) ;
V_3 -> V_94 [ V_26 ] . V_98 = V_16 ;
* V_8 = V_7 ;
return 0 ;
}
V_96 = V_7 -> V_87 + 1 ;
if ( ( * V_4 == 0 ) || ( * V_4 == V_96 ) ) {
V_37 = F_37 ( V_3 , V_7 -> V_42 ,
V_7 -> V_87 + V_16 ) ;
if ( ! V_37 ) {
V_37 = F_43 ( V_3 -> V_94 [ V_26 ] . V_7 , V_7 -> V_42 ,
F_44 ( V_7 ) + V_16 ) ;
if ( V_37 )
continue;
* V_4 = V_96 ;
V_3 -> V_94 [ V_26 ] . V_98 += V_16 ;
* V_8 = V_7 ;
return 0 ;
}
}
V_96 = V_7 -> V_42 - V_16 ;
if ( ( * V_4 == 0 ) || ( * V_4 == V_96 ) ) {
V_37 = F_37 ( V_3 ,
V_7 -> V_42 - V_16 ,
V_7 -> V_87 ) ;
if ( ! V_37 ) {
V_37 = F_43 ( V_3 -> V_94 [ V_26 ] . V_7 ,
V_7 -> V_42 - V_16 ,
F_44 ( V_7 ) + V_16 ) ;
if ( V_37 )
continue;
* V_4 = V_96 ;
V_3 -> V_94 [ V_26 ] . V_98 += V_16 ;
* V_8 = V_7 ;
return 0 ;
}
}
}
return - V_38 ;
}
static struct V_1 * F_45 ( T_2 V_4 , T_2 V_16 ,
T_2 V_83 , int V_99 , struct V_2 * V_3 )
{
struct V_1 * V_7 = F_2 ( 0 , V_16 , V_9 ,
F_39 ( & V_3 -> V_33 ) ) ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_79 V_84 ;
unsigned long V_90 , F_10 ;
int V_37 , V_26 , V_27 ;
V_99 = V_99 || ! ( V_3 -> V_77 & V_78 ) ;
V_84 . V_81 = V_83 - 1 ;
V_84 . V_82 = V_4 & V_84 . V_81 ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_84 . V_15 = & V_24 -> V_61 ;
if ( V_99 ) {
F_10 = 0x100000UL ;
V_90 = V_4 < F_10 ? V_4 : 0 ;
} else {
F_10 = ~ 0UL ;
V_90 = 0x100000UL + V_4 ;
}
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
#ifdef F_3
if ( V_3 -> V_13 ) {
V_37 = F_40 ( V_3 -> V_13 -> V_91 ,
V_7 , V_16 , 1 , V_90 , 0 ,
F_36 , & V_84 ) ;
} else
#endif
{
V_37 = F_41 ( & V_10 ,
V_7 , V_16 , V_90 , F_10 , 1 ,
F_36 , & V_84 ) ;
}
if ( V_37 == 0 )
break;
V_84 . V_15 = & V_24 -> V_62 ;
}
if ( V_37 == 0 || V_99 )
break;
V_99 = 1 ;
}
if ( V_37 != 0 ) {
F_6 ( V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
static int F_46 ( struct V_2 * V_3 , unsigned int V_100 , unsigned long V_42 , unsigned long V_87 )
{
struct V_23 * V_84 = V_3 -> V_25 ;
unsigned long V_5 = V_87 - V_42 + 1 ;
int V_37 = 0 ;
if ( V_87 < V_42 )
return - V_38 ;
switch ( V_100 ) {
case V_101 :
V_37 = F_9 ( & V_84 -> V_62 , V_42 , V_5 ) ;
if ( ! V_37 )
F_29 ( V_3 , V_42 , V_5 , NULL , NULL ) ;
break;
case V_102 :
V_37 = F_13 ( & V_84 -> V_62 , V_42 , V_5 ) ;
break;
default:
V_37 = - V_38 ;
}
return V_37 ;
}
static int F_47 ( struct V_2 * V_3 , unsigned int V_100 , unsigned long V_42 , unsigned long V_87 )
{
struct V_23 * V_84 = V_3 -> V_25 ;
unsigned long V_5 ;
int V_37 = 0 ;
#if F_48 ( V_103 )
if ( V_42 < 0x100 )
V_42 = 0x100 ;
#endif
V_5 = V_87 - V_42 + 1 ;
if ( V_87 < V_42 )
return - V_38 ;
if ( V_87 > V_104 )
return - V_38 ;
switch ( V_100 ) {
case V_101 :
if ( F_9 ( & V_84 -> V_35 , V_42 , V_5 ) != 0 ) {
V_37 = - V_95 ;
break;
}
#ifdef F_49
if ( V_105 )
F_14 ( V_3 , V_42 , V_5 ) ;
#endif
break;
case V_102 :
F_13 ( & V_84 -> V_35 , V_42 , V_5 ) ;
break;
default:
V_37 = - V_38 ;
break;
}
return V_37 ;
}
static inline int F_50 ( struct V_2 * V_3 )
{
return - V_71 ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_23 * V_84 ;
V_84 = F_16 ( sizeof( struct V_23 ) , V_20 ) ;
if ( ! V_84 )
return - V_22 ;
V_84 -> V_62 . V_19 = & V_84 -> V_62 ;
V_84 -> V_61 . V_19 = & V_84 -> V_61 ;
V_84 -> V_35 . V_19 = & V_84 -> V_35 ;
V_3 -> V_25 = ( void * ) V_84 ;
F_50 ( V_3 ) ;
return 0 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_23 * V_84 = V_3 -> V_25 ;
struct V_14 * V_17 , * V_18 ;
for ( V_17 = V_84 -> V_61 . V_19 ; V_17 != & V_84 -> V_61 ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
}
for ( V_17 = V_84 -> V_62 . V_19 ; V_17 != & V_84 -> V_62 ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
}
for ( V_17 = V_84 -> V_35 . V_19 ; V_17 != & V_84 -> V_35 ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
}
}
static T_6 F_53 ( struct V_106 * V_33 ,
struct V_107 * V_92 , char * V_108 )
{
struct V_2 * V_3 = F_54 ( V_33 ) ;
struct V_23 * V_84 ;
struct V_14 * V_17 ;
T_6 V_37 = 0 ;
F_24 ( & V_3 -> V_44 ) ;
V_84 = V_3 -> V_25 ;
for ( V_17 = V_84 -> V_35 . V_19 ; V_17 != & V_84 -> V_35 ; V_17 = V_17 -> V_19 ) {
if ( V_37 > ( V_109 - 10 ) )
continue;
V_37 += snprintf ( & V_108 [ V_37 ] , ( V_109 - V_37 - 1 ) ,
L_18 ,
( ( unsigned long ) V_17 -> V_4 ) ,
( ( unsigned long ) V_17 -> V_4 + V_17 -> V_16 - 1 ) ) ;
}
F_23 ( & V_3 -> V_44 ) ;
return V_37 ;
}
static T_6 F_55 ( struct V_106 * V_33 ,
struct V_107 * V_92 ,
const char * V_108 , T_7 V_36 )
{
struct V_2 * V_3 = F_54 ( V_33 ) ;
unsigned long V_110 , V_111 ;
unsigned int V_112 = V_101 ;
T_6 V_37 = 0 ;
V_37 = sscanf ( V_108 , L_19 , & V_110 , & V_111 ) ;
if ( V_37 != 2 ) {
V_37 = sscanf ( V_108 , L_20 , & V_110 , & V_111 ) ;
V_112 = V_102 ;
if ( V_37 != 2 ) {
V_37 = sscanf ( V_108 , L_21 , & V_110 ,
& V_111 ) ;
V_112 = V_101 ;
if ( V_37 != 2 )
return - V_38 ;
}
}
if ( V_111 < V_110 )
return - V_38 ;
F_24 ( & V_3 -> V_44 ) ;
V_37 = F_47 ( V_3 , V_112 , V_110 , V_111 ) ;
F_23 ( & V_3 -> V_44 ) ;
return V_37 ? V_37 : V_36 ;
}
static T_6 F_56 ( struct V_106 * V_33 ,
struct V_107 * V_92 , char * V_108 )
{
struct V_2 * V_3 = F_54 ( V_33 ) ;
struct V_23 * V_84 ;
struct V_14 * V_17 ;
T_6 V_37 = 0 ;
F_24 ( & V_3 -> V_44 ) ;
V_84 = V_3 -> V_25 ;
for ( V_17 = V_84 -> V_61 . V_19 ; V_17 != & V_84 -> V_61 ;
V_17 = V_17 -> V_19 ) {
if ( V_37 > ( V_109 - 10 ) )
continue;
V_37 += snprintf ( & V_108 [ V_37 ] , ( V_109 - V_37 - 1 ) ,
L_18 ,
( ( unsigned long ) V_17 -> V_4 ) ,
( ( unsigned long ) V_17 -> V_4 + V_17 -> V_16 - 1 ) ) ;
}
for ( V_17 = V_84 -> V_62 . V_19 ; V_17 != & V_84 -> V_62 ; V_17 = V_17 -> V_19 ) {
if ( V_37 > ( V_109 - 10 ) )
continue;
V_37 += snprintf ( & V_108 [ V_37 ] , ( V_109 - V_37 - 1 ) ,
L_18 ,
( ( unsigned long ) V_17 -> V_4 ) ,
( ( unsigned long ) V_17 -> V_4 + V_17 -> V_16 - 1 ) ) ;
}
F_23 ( & V_3 -> V_44 ) ;
return V_37 ;
}
static T_6 F_57 ( struct V_106 * V_33 ,
struct V_107 * V_92 ,
const char * V_108 , T_7 V_36 )
{
struct V_2 * V_3 = F_54 ( V_33 ) ;
unsigned long V_110 , V_111 ;
unsigned int V_112 = V_101 ;
T_6 V_37 = 0 ;
V_37 = sscanf ( V_108 , L_19 , & V_110 , & V_111 ) ;
if ( V_37 != 2 ) {
V_37 = sscanf ( V_108 , L_20 , & V_110 , & V_111 ) ;
V_112 = V_102 ;
if ( V_37 != 2 ) {
V_37 = sscanf ( V_108 , L_21 , & V_110 ,
& V_111 ) ;
V_112 = V_101 ;
if ( V_37 != 2 )
return - V_38 ;
}
}
if ( V_111 < V_110 )
return - V_38 ;
F_24 ( & V_3 -> V_44 ) ;
V_37 = F_46 ( V_3 , V_112 , V_110 , V_111 ) ;
F_23 ( & V_3 -> V_44 ) ;
return V_37 ? V_37 : V_36 ;
}
static int F_58 ( struct V_106 * V_33 ,
struct V_113 * V_114 )
{
struct V_2 * V_3 = F_54 ( V_33 ) ;
if ( V_3 -> V_115 != & V_116 )
return 0 ;
return F_59 ( & V_33 -> V_117 , & V_118 ) ;
}
static void F_60 ( struct V_106 * V_33 ,
struct V_113 * V_114 )
{
struct V_2 * V_3 = F_54 ( V_33 ) ;
if ( V_3 -> V_115 != & V_116 )
return;
F_61 ( & V_33 -> V_117 , & V_118 ) ;
}
static int T_8 F_62 ( void )
{
return F_63 ( & V_119 ) ;
}
static void T_9 F_64 ( void )
{
F_65 ( & V_119 ) ;
}
