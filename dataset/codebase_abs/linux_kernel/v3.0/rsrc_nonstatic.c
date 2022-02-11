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
F_15 ( V_33 , & V_3 -> V_34 , L_2 ,
V_4 , V_4 + V_16 - 1 ) ;
V_30 = F_16 ( 256 , V_20 ) ;
if ( ! V_30 ) {
F_12 ( L_3 ) ;
F_15 ( V_35 , & V_3 -> V_34 ,
L_4 ) ;
return;
}
for ( V_26 = V_4 , V_32 = 0 ; V_26 < V_4 + V_16 ; V_26 += 8 ) {
V_7 = F_1 ( V_3 , V_26 , 8 , V_36 , L_5 ) ;
if ( ! V_7 )
continue;
V_31 = F_17 ( V_26 ) ;
for ( V_27 = 1 ; V_27 < 8 ; V_27 ++ )
if ( F_17 ( V_26 + V_27 ) != V_31 )
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
V_7 = F_1 ( V_3 , V_26 , 8 , V_36 , L_5 ) ;
if ( ! V_7 ) {
if ( ! V_29 )
F_12 ( L_6 ) ;
if ( ! V_28 )
V_28 = V_29 = V_26 ;
continue;
}
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
if ( F_17 ( V_26 + V_27 ) != V_32 )
break;
F_7 ( V_7 ) ;
if ( V_27 < 8 ) {
if ( ! V_29 )
F_12 ( L_6 ) ;
if ( ! V_28 )
V_28 = V_29 = V_26 ;
} else {
if ( V_28 ) {
F_13 ( & V_24 -> V_37 , V_28 , V_26 - V_28 ) ;
F_12 ( L_7 , V_28 , V_26 - 1 ) ;
V_28 = 0 ;
}
}
}
if ( V_28 ) {
if ( ( V_16 > 16 ) && ( V_28 == V_4 ) && ( V_26 == V_4 + V_16 ) ) {
F_13 ( & V_24 -> V_37 , V_28 , V_26 - V_28 ) ;
F_12 ( L_8 ) ;
return;
} else {
F_13 ( & V_24 -> V_37 , V_28 , V_26 - V_28 ) ;
F_12 ( L_7 , V_28 , V_26 - 1 ) ;
}
}
F_12 ( V_29 ? L_3 : L_9 ) ;
}
static int F_18 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int * V_38 )
{
int V_39 = - V_40 ;
if ( V_3 -> V_41 ) {
F_19 ( & V_3 -> V_34 , L_10 ) ;
return 0 ;
}
V_3 -> V_42 . V_7 = V_7 ;
V_3 -> V_43 = F_20 ( V_7 -> V_44 , V_3 -> V_45 ) ;
if ( V_3 -> V_43 ) {
F_21 ( & V_3 -> V_46 ) ;
if ( V_3 -> V_47 -> V_48 )
V_39 = V_3 -> V_47 -> V_48 ( V_3 , V_38 ) ;
F_22 ( & V_3 -> V_46 ) ;
F_23 ( V_3 -> V_43 ) ;
V_3 -> V_43 = NULL ;
}
V_3 -> V_42 . V_7 = NULL ;
if ( ( V_39 ) || ( * V_38 == 0 ) )
return - V_40 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int * V_49 )
{
T_4 V_15 ;
int V_26 , V_50 = 0 , V_30 = - 1 , V_51 ;
void T_5 * V_52 ;
V_52 = F_20 ( V_7 -> V_44 , V_3 -> V_45 ) ;
if ( V_52 ) {
V_15 . V_15 = 0 ;
V_15 . V_53 = V_54 ;
V_15 . V_55 = 0 ;
V_15 . V_7 = V_7 ;
V_15 . V_56 = 0 ;
V_3 -> V_57 -> V_58 ( V_3 , & V_15 ) ;
for ( V_26 = 0 ; V_26 < V_3 -> V_45 ; V_26 += 44 ) {
V_51 = F_25 ( V_52 + V_26 ) ;
V_50 += V_51 ;
V_30 &= V_51 ;
}
V_15 . V_53 = 0 ;
V_3 -> V_57 -> V_58 ( V_3 , & V_15 ) ;
F_23 ( V_52 ) ;
}
if ( V_30 == - 1 )
return - V_40 ;
* V_49 = V_50 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned long V_4 , unsigned long V_5 ,
int V_48 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
unsigned int * V_49 ) )
{
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_1 * V_59 , * V_60 ;
unsigned int V_61 = 1 , V_62 = 1 ;
int V_39 = - V_40 ;
V_59 = F_1 ( V_3 , V_4 , V_5 / 2 , V_9 , L_11 ) ;
V_60 = F_1 ( V_3 , V_4 + V_5 / 2 , V_5 / 2 , V_9 ,
L_11 ) ;
if ( V_59 && V_60 ) {
V_39 = 0 ;
if ( V_48 ) {
V_39 = V_48 ( V_3 , V_59 , & V_61 ) ;
V_39 += V_48 ( V_3 , V_60 , & V_62 ) ;
}
}
F_7 ( V_60 ) ;
F_7 ( V_59 ) ;
F_19 ( & V_3 -> V_34 , L_12 ,
V_4 , V_4 + V_5 - 1 , V_59 , V_60 , V_39 , V_61 , V_62 ) ;
if ( ( V_39 ) || ( V_61 != V_62 ) || ( V_61 == 0 ) )
return - V_40 ;
if ( V_48 && ! V_3 -> V_41 ) {
F_9 ( & V_24 -> V_63 , V_4 , V_5 ) ;
F_13 ( & V_24 -> V_64 , V_4 , V_5 ) ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , T_2 V_4 , T_2 V_16 ,
int V_48 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
unsigned int * V_49 ) ,
int F_28 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
unsigned int * V_49 ) )
{
struct V_23 * V_24 = V_3 -> V_25 ;
T_2 V_26 , V_27 , V_28 , V_65 , V_66 ;
F_15 ( V_33 , & V_3 -> V_34 , L_13 ,
V_4 , V_4 + V_16 - 1 ) ;
V_28 = V_65 = 0 ;
V_66 = ( V_16 < 0x20000 ) ? 0x2000 : ( ( V_16 >> 4 ) & ~ 0x1fff ) ;
if ( V_66 > 0x800000 )
V_66 = 0x800000 ;
if ( V_66 < 2 * V_3 -> V_45 )
V_66 = 2 * V_3 -> V_45 ;
for ( V_26 = V_27 = V_4 ; V_26 < V_4 + V_16 ; V_26 = V_27 + V_66 ) {
if ( ! V_65 ) {
for ( V_27 = V_26 ; V_27 < V_4 + V_16 ; V_27 += V_66 ) {
if ( ! F_26 ( V_3 , V_27 , V_66 , V_48 ) )
break;
}
V_65 = ( ( V_26 == V_4 ) && ( V_27 == V_4 + V_16 ) ) ;
}
if ( ( V_65 ) && ( F_28 ) ) {
for ( V_27 = V_26 ; V_27 < V_4 + V_16 ; V_27 += V_66 )
if ( ! F_26 ( V_3 , V_27 , V_66 , F_28 ) )
break;
}
if ( V_26 != V_27 ) {
if ( ! V_28 )
F_12 ( L_6 ) ;
F_12 ( L_14 , V_26 , V_27 - 1 ) ;
F_13 ( & V_24 -> V_64 , V_26 , V_27 - V_26 ) ;
V_28 += V_27 - V_26 ;
}
}
F_12 ( V_28 ? L_3 : L_9 ) ;
return V_16 - V_28 ;
}
static T_2 F_29 ( struct V_14 * V_67 , struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
T_2 V_68 ;
if ( V_67 == & V_24 -> V_64 )
return 0 ;
V_68 = F_29 ( V_67 -> V_19 , V_3 ) ;
if ( V_68 ) {
if ( V_67 -> V_4 >= 0x100000 )
F_13 ( & V_24 -> V_64 , V_67 -> V_4 , V_67 -> V_16 ) ;
return V_68 ;
}
if ( V_67 -> V_4 < 0x100000 )
return 0 ;
return F_27 ( V_3 , V_67 -> V_4 , V_67 -> V_16 , F_18 , F_24 ) ;
}
static int F_30 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_14 * V_67 , V_70 ;
static unsigned char V_71 [] = { 0xd0 , 0xe0 , 0xc0 , 0xf0 } ;
unsigned long V_30 , V_26 , V_68 = 0 ;
struct V_23 * V_24 = V_3 -> V_25 ;
if ( V_69 & V_72 ) {
if ( F_29 ( V_24 -> V_64 . V_19 , V_3 ) > 0 )
return 0 ;
if ( V_24 -> V_63 . V_19 != & V_24 -> V_63 )
return 0 ;
F_15 ( V_73 , & V_3 -> V_34 ,
L_15 ) ;
return - V_74 ;
}
for ( V_67 = V_24 -> V_64 . V_19 ; V_67 != & V_24 -> V_64 ; V_67 = V_70 . V_19 ) {
V_70 = * V_67 ;
if ( V_70 . V_4 >= 0x100000 )
continue;
if ( ( V_70 . V_4 | V_70 . V_16 ) & 0xffff ) {
V_68 += F_27 ( V_3 , V_70 . V_4 , V_70 . V_16 , F_18 ,
F_24 ) ;
continue;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_30 = V_71 [ V_26 ] << 12 ;
if ( ( V_30 >= V_70 . V_4 ) && ( V_30 + 0x10000 <= V_70 . V_4 + V_70 . V_16 ) ) {
if ( V_68 >= V_75 )
F_13 ( & V_24 -> V_64 , V_30 , 0x10000 ) ;
else
V_68 += F_27 ( V_3 , V_30 , 0x10000 ,
F_18 , F_24 ) ;
}
}
}
if ( V_68 > 0 )
return 0 ;
return - V_74 ;
}
static int F_30 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_14 * V_67 , V_70 ;
struct V_23 * V_24 = V_3 -> V_25 ;
unsigned long V_68 = 0 ;
for ( V_67 = V_24 -> V_64 . V_19 ; V_67 != & V_24 -> V_64 ; V_67 = V_70 . V_19 ) {
V_70 = * V_67 ;
V_68 += F_27 ( V_3 , V_70 . V_4 , V_70 . V_16 , F_18 , F_24 ) ;
}
if ( V_68 > 0 )
return 0 ;
return - V_74 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_25 ;
unsigned int V_69 = V_76 ;
int V_39 ;
if ( ! V_77 || ! ( V_3 -> V_78 & V_79 ) )
return 0 ;
if ( V_3 -> V_80 & V_81 )
V_69 = V_72 ;
V_39 = F_30 ( V_3 , V_69 ) ;
if ( V_24 -> V_63 . V_19 != & V_24 -> V_63 )
return 0 ;
return V_39 ;
}
static T_1 F_32 ( struct V_82 * V_83 ,
T_1 V_44 )
{
T_1 V_39 ;
V_39 = ( V_44 & ~ V_83 -> V_84 ) + V_83 -> V_85 ;
if ( V_39 < V_44 )
V_39 += V_83 -> V_84 + 1 ;
return V_39 ;
}
static T_1
F_33 ( void * V_83 , const struct V_1 * V_7 ,
T_1 V_5 , T_1 V_86 )
{
struct V_82 * V_87 = V_83 ;
struct V_14 * V_67 ;
T_1 V_44 ;
V_44 = F_32 ( V_87 , V_7 -> V_44 ) ;
for ( V_67 = V_87 -> V_15 -> V_19 ; V_67 != V_87 -> V_15 ; V_67 = V_67 -> V_19 ) {
unsigned long V_88 = V_67 -> V_4 ;
unsigned long V_89 = V_67 -> V_4 + V_67 -> V_16 - 1 ;
if ( V_44 < V_88 )
V_44 = F_32 ( V_87 , V_88 ) ;
if ( V_44 >= V_7 -> V_90 )
break;
if ( ( V_44 + V_5 - 1 ) <= V_89 )
break;
}
if ( V_67 == V_87 -> V_15 )
V_44 = V_7 -> V_90 ;
return V_44 ;
}
static int F_34 ( struct V_2 * V_3 ,
unsigned long V_91 ,
unsigned long V_92 )
{
struct V_14 * V_67 ;
struct V_23 * V_24 = V_3 -> V_25 ;
int V_39 = - V_22 ;
for ( V_67 = V_24 -> V_37 . V_19 ; V_67 != & V_24 -> V_37 ; V_67 = V_67 -> V_19 ) {
unsigned long V_44 = V_67 -> V_4 ;
unsigned long V_90 = V_67 -> V_4 + V_67 -> V_16 - 1 ;
if ( V_44 > V_91 || V_92 > V_90 )
continue;
V_39 = 0 ;
}
return V_39 ;
}
static struct V_1 * F_35 ( struct V_2 * V_3 ,
unsigned long V_4 , int V_16 ,
unsigned long V_86 )
{
struct V_1 * V_7 = F_2 ( 0 , V_16 , V_36 ,
F_36 ( & V_3 -> V_34 ) ) ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_82 V_87 ;
unsigned long V_93 = V_4 ;
int V_39 ;
V_87 . V_84 = V_86 - 1 ;
V_87 . V_85 = V_4 & V_87 . V_84 ;
V_87 . V_15 = & V_24 -> V_37 ;
#ifdef F_3
if ( V_3 -> V_13 ) {
V_39 = F_37 ( V_3 -> V_13 -> V_94 , V_7 , V_16 , 1 ,
V_93 , 0 , F_33 , & V_87 ) ;
} else
#endif
V_39 = F_38 ( & V_11 , V_7 , V_16 , V_93 , ~ 0UL ,
1 , F_33 , & V_87 ) ;
if ( V_39 != 0 ) {
F_6 ( V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
static int F_39 ( struct V_2 * V_3 , unsigned int V_95 ,
unsigned int * V_4 , unsigned int V_16 ,
unsigned int V_86 , struct V_1 * * V_8 )
{
int V_26 , V_39 = 0 ;
for ( V_26 = 0 ; V_26 < V_96 ; V_26 ++ ) {
if ( ! V_3 -> V_97 [ V_26 ] . V_7 )
continue;
if ( ! * V_4 )
continue;
if ( ( V_3 -> V_97 [ V_26 ] . V_7 -> V_44 & ( V_86 - 1 ) ) == * V_4 )
return - V_98 ;
}
for ( V_26 = 0 ; V_26 < V_96 ; V_26 ++ ) {
struct V_1 * V_7 = V_3 -> V_97 [ V_26 ] . V_7 ;
unsigned int V_99 ;
if ( V_7 && ( V_7 -> V_53 & V_100 ) !=
( V_95 & V_100 ) )
continue;
if ( ! V_7 ) {
if ( V_86 == 0 )
V_86 = 0x10000 ;
V_7 = V_3 -> V_97 [ V_26 ] . V_7 = F_35 ( V_3 ,
* V_4 , V_16 ,
V_86 ) ;
if ( ! V_7 )
return - V_40 ;
* V_4 = V_7 -> V_44 ;
V_3 -> V_97 [ V_26 ] . V_7 -> V_53 =
( ( V_7 -> V_53 & ~ V_100 ) |
( V_95 & V_100 ) ) ;
V_3 -> V_97 [ V_26 ] . V_101 = V_16 ;
* V_8 = V_7 ;
return 0 ;
}
V_99 = V_7 -> V_90 + 1 ;
if ( ( * V_4 == 0 ) || ( * V_4 == V_99 ) ) {
V_39 = F_34 ( V_3 , V_7 -> V_44 ,
V_7 -> V_90 + V_16 ) ;
if ( ! V_39 ) {
V_39 = F_40 ( V_3 -> V_97 [ V_26 ] . V_7 , V_7 -> V_44 ,
V_7 -> V_90 - V_7 -> V_44 + V_16 + 1 ) ;
if ( V_39 )
continue;
* V_4 = V_99 ;
V_3 -> V_97 [ V_26 ] . V_101 += V_16 ;
* V_8 = V_7 ;
return 0 ;
}
}
V_99 = V_7 -> V_44 - V_16 ;
if ( ( * V_4 == 0 ) || ( * V_4 == V_99 ) ) {
V_39 = F_34 ( V_3 ,
V_7 -> V_44 - V_16 ,
V_7 -> V_90 ) ;
if ( ! V_39 ) {
V_39 = F_40 ( V_3 -> V_97 [ V_26 ] . V_7 ,
V_7 -> V_44 - V_16 ,
V_7 -> V_90 - V_7 -> V_44 + V_16 + 1 ) ;
if ( V_39 )
continue;
* V_4 = V_99 ;
V_3 -> V_97 [ V_26 ] . V_101 += V_16 ;
* V_8 = V_7 ;
return 0 ;
}
}
}
return - V_40 ;
}
static struct V_1 * F_41 ( T_2 V_4 , T_2 V_16 ,
T_2 V_86 , int V_102 , struct V_2 * V_3 )
{
struct V_1 * V_7 = F_2 ( 0 , V_16 , V_9 ,
F_36 ( & V_3 -> V_34 ) ) ;
struct V_23 * V_24 = V_3 -> V_25 ;
struct V_82 V_87 ;
unsigned long V_93 , F_10 ;
int V_39 , V_26 , V_27 ;
V_102 = V_102 || ! ( V_3 -> V_80 & V_81 ) ;
V_87 . V_84 = V_86 - 1 ;
V_87 . V_85 = V_4 & V_87 . V_84 ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_87 . V_15 = & V_24 -> V_63 ;
if ( V_102 ) {
F_10 = 0x100000UL ;
V_93 = V_4 < F_10 ? V_4 : 0 ;
} else {
F_10 = ~ 0UL ;
V_93 = 0x100000UL + V_4 ;
}
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
#ifdef F_3
if ( V_3 -> V_13 ) {
V_39 = F_37 ( V_3 -> V_13 -> V_94 ,
V_7 , V_16 , 1 , V_93 , 0 ,
F_33 , & V_87 ) ;
} else
#endif
{
V_39 = F_38 ( & V_10 ,
V_7 , V_16 , V_93 , F_10 , 1 ,
F_33 , & V_87 ) ;
}
if ( V_39 == 0 )
break;
V_87 . V_15 = & V_24 -> V_64 ;
}
if ( V_39 == 0 || V_102 )
break;
V_102 = 1 ;
}
if ( V_39 != 0 ) {
F_6 ( V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
static int F_42 ( struct V_2 * V_3 , unsigned int V_103 , unsigned long V_44 , unsigned long V_90 )
{
struct V_23 * V_87 = V_3 -> V_25 ;
unsigned long V_5 = V_90 - V_44 + 1 ;
int V_39 = 0 ;
if ( V_90 < V_44 )
return - V_40 ;
switch ( V_103 ) {
case V_104 :
V_39 = F_9 ( & V_87 -> V_64 , V_44 , V_5 ) ;
if ( ! V_39 )
F_27 ( V_3 , V_44 , V_5 , NULL , NULL ) ;
break;
case V_105 :
V_39 = F_13 ( & V_87 -> V_64 , V_44 , V_5 ) ;
break;
default:
V_39 = - V_40 ;
}
return V_39 ;
}
static int F_43 ( struct V_2 * V_3 , unsigned int V_103 , unsigned long V_44 , unsigned long V_90 )
{
struct V_23 * V_87 = V_3 -> V_25 ;
unsigned long V_5 ;
int V_39 = 0 ;
#if F_44 ( V_106 )
if ( V_44 < 0x100 )
V_44 = 0x100 ;
#endif
V_5 = V_90 - V_44 + 1 ;
if ( V_90 < V_44 )
return - V_40 ;
if ( V_90 > V_107 )
return - V_40 ;
switch ( V_103 ) {
case V_104 :
if ( F_9 ( & V_87 -> V_37 , V_44 , V_5 ) != 0 ) {
V_39 = - V_98 ;
break;
}
#ifdef F_45
if ( V_108 )
F_14 ( V_3 , V_44 , V_5 ) ;
#endif
break;
case V_105 :
F_13 ( & V_87 -> V_37 , V_44 , V_5 ) ;
break;
default:
V_39 = - V_40 ;
break;
}
return V_39 ;
}
static inline int F_46 ( struct V_2 * V_3 )
{
return - V_74 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_23 * V_87 ;
V_87 = F_16 ( sizeof( struct V_23 ) , V_20 ) ;
if ( ! V_87 )
return - V_22 ;
V_87 -> V_64 . V_19 = & V_87 -> V_64 ;
V_87 -> V_63 . V_19 = & V_87 -> V_63 ;
V_87 -> V_37 . V_19 = & V_87 -> V_37 ;
V_3 -> V_25 = ( void * ) V_87 ;
F_46 ( V_3 ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_23 * V_87 = V_3 -> V_25 ;
struct V_14 * V_17 , * V_18 ;
for ( V_17 = V_87 -> V_63 . V_19 ; V_17 != & V_87 -> V_63 ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
}
for ( V_17 = V_87 -> V_64 . V_19 ; V_17 != & V_87 -> V_64 ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
}
for ( V_17 = V_87 -> V_37 . V_19 ; V_17 != & V_87 -> V_37 ; V_17 = V_18 ) {
V_18 = V_17 -> V_19 ;
F_6 ( V_17 ) ;
}
}
static T_6 F_49 ( struct V_109 * V_34 ,
struct V_110 * V_95 , char * V_111 )
{
struct V_2 * V_3 = F_50 ( V_34 ) ;
struct V_23 * V_87 ;
struct V_14 * V_17 ;
T_6 V_39 = 0 ;
F_22 ( & V_3 -> V_46 ) ;
V_87 = V_3 -> V_25 ;
for ( V_17 = V_87 -> V_37 . V_19 ; V_17 != & V_87 -> V_37 ; V_17 = V_17 -> V_19 ) {
if ( V_39 > ( V_112 - 10 ) )
continue;
V_39 += snprintf ( & V_111 [ V_39 ] , ( V_112 - V_39 - 1 ) ,
L_16 ,
( ( unsigned long ) V_17 -> V_4 ) ,
( ( unsigned long ) V_17 -> V_4 + V_17 -> V_16 - 1 ) ) ;
}
F_21 ( & V_3 -> V_46 ) ;
return V_39 ;
}
static T_6 F_51 ( struct V_109 * V_34 ,
struct V_110 * V_95 ,
const char * V_111 , T_7 V_38 )
{
struct V_2 * V_3 = F_50 ( V_34 ) ;
unsigned long V_113 , V_114 ;
unsigned int V_115 = V_104 ;
T_6 V_39 = 0 ;
V_39 = sscanf ( V_111 , L_17 , & V_113 , & V_114 ) ;
if ( V_39 != 2 ) {
V_39 = sscanf ( V_111 , L_18 , & V_113 , & V_114 ) ;
V_115 = V_105 ;
if ( V_39 != 2 ) {
V_39 = sscanf ( V_111 , L_19 , & V_113 ,
& V_114 ) ;
V_115 = V_104 ;
if ( V_39 != 2 )
return - V_40 ;
}
}
if ( V_114 < V_113 )
return - V_40 ;
F_22 ( & V_3 -> V_46 ) ;
V_39 = F_43 ( V_3 , V_115 , V_113 , V_114 ) ;
F_21 ( & V_3 -> V_46 ) ;
return V_39 ? V_39 : V_38 ;
}
static T_6 F_52 ( struct V_109 * V_34 ,
struct V_110 * V_95 , char * V_111 )
{
struct V_2 * V_3 = F_50 ( V_34 ) ;
struct V_23 * V_87 ;
struct V_14 * V_17 ;
T_6 V_39 = 0 ;
F_22 ( & V_3 -> V_46 ) ;
V_87 = V_3 -> V_25 ;
for ( V_17 = V_87 -> V_63 . V_19 ; V_17 != & V_87 -> V_63 ;
V_17 = V_17 -> V_19 ) {
if ( V_39 > ( V_112 - 10 ) )
continue;
V_39 += snprintf ( & V_111 [ V_39 ] , ( V_112 - V_39 - 1 ) ,
L_16 ,
( ( unsigned long ) V_17 -> V_4 ) ,
( ( unsigned long ) V_17 -> V_4 + V_17 -> V_16 - 1 ) ) ;
}
for ( V_17 = V_87 -> V_64 . V_19 ; V_17 != & V_87 -> V_64 ; V_17 = V_17 -> V_19 ) {
if ( V_39 > ( V_112 - 10 ) )
continue;
V_39 += snprintf ( & V_111 [ V_39 ] , ( V_112 - V_39 - 1 ) ,
L_16 ,
( ( unsigned long ) V_17 -> V_4 ) ,
( ( unsigned long ) V_17 -> V_4 + V_17 -> V_16 - 1 ) ) ;
}
F_21 ( & V_3 -> V_46 ) ;
return V_39 ;
}
static T_6 F_53 ( struct V_109 * V_34 ,
struct V_110 * V_95 ,
const char * V_111 , T_7 V_38 )
{
struct V_2 * V_3 = F_50 ( V_34 ) ;
unsigned long V_113 , V_114 ;
unsigned int V_115 = V_104 ;
T_6 V_39 = 0 ;
V_39 = sscanf ( V_111 , L_17 , & V_113 , & V_114 ) ;
if ( V_39 != 2 ) {
V_39 = sscanf ( V_111 , L_18 , & V_113 , & V_114 ) ;
V_115 = V_105 ;
if ( V_39 != 2 ) {
V_39 = sscanf ( V_111 , L_19 , & V_113 ,
& V_114 ) ;
V_115 = V_104 ;
if ( V_39 != 2 )
return - V_40 ;
}
}
if ( V_114 < V_113 )
return - V_40 ;
F_22 ( & V_3 -> V_46 ) ;
V_39 = F_42 ( V_3 , V_115 , V_113 , V_114 ) ;
F_21 ( & V_3 -> V_46 ) ;
return V_39 ? V_39 : V_38 ;
}
static int T_8 F_54 ( struct V_109 * V_34 ,
struct V_116 * V_117 )
{
struct V_2 * V_3 = F_50 ( V_34 ) ;
if ( V_3 -> V_118 != & V_119 )
return 0 ;
return F_55 ( & V_34 -> V_120 , & V_121 ) ;
}
static void T_9 F_56 ( struct V_109 * V_34 ,
struct V_116 * V_117 )
{
struct V_2 * V_3 = F_50 ( V_34 ) ;
if ( V_3 -> V_118 != & V_119 )
return;
F_57 ( & V_34 -> V_120 , & V_121 ) ;
}
static int T_10 F_58 ( void )
{
return F_59 ( & V_122 ) ;
}
static void T_11 F_60 ( void )
{
F_61 ( & V_122 ) ;
}
