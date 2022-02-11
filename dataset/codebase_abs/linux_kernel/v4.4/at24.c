static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned * V_4 )
{
unsigned V_5 ;
if ( V_3 -> V_6 . V_7 & V_8 ) {
V_5 = * V_4 >> 16 ;
* V_4 &= 0xffff ;
} else {
V_5 = * V_4 >> 8 ;
* V_4 &= 0xff ;
}
return V_3 -> V_9 [ V_5 ] ;
}
static T_1 F_2 ( struct V_2 * V_3 , char * V_10 ,
unsigned V_4 , T_2 V_11 )
{
struct V_12 V_13 [ 2 ] ;
T_3 V_14 [ 2 ] ;
struct V_1 * V_9 ;
unsigned long V_15 , V_16 ;
int V_17 , V_5 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_18 )
V_11 = V_18 ;
if ( V_3 -> V_19 ) {
if ( V_11 > V_20 )
V_11 = V_20 ;
} else {
V_5 = 0 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_14 [ V_5 ++ ] = V_4 >> 8 ;
V_14 [ V_5 ++ ] = V_4 ;
V_13 [ 0 ] . V_21 = V_9 -> V_21 ;
V_13 [ 0 ] . V_10 = V_14 ;
V_13 [ 0 ] . V_22 = V_5 ;
V_13 [ 1 ] . V_21 = V_9 -> V_21 ;
V_13 [ 1 ] . V_7 = V_23 ;
V_13 [ 1 ] . V_10 = V_10 ;
V_13 [ 1 ] . V_22 = V_11 ;
}
V_15 = V_24 + F_3 ( V_25 ) ;
do {
V_16 = V_24 ;
if ( V_3 -> V_19 ) {
V_17 = F_4 ( V_9 , V_4 ,
V_11 , V_10 ) ;
} else {
V_17 = F_5 ( V_9 -> V_26 , V_13 , 2 ) ;
if ( V_17 == 2 )
V_17 = V_11 ;
}
F_6 ( & V_9 -> V_27 , L_1 ,
V_11 , V_4 , V_17 , V_24 ) ;
if ( V_17 == V_11 )
return V_11 ;
F_7 ( 1 ) ;
} while ( F_8 ( V_16 , V_15 ) );
return - V_28 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
char * V_10 , T_4 V_29 , T_2 V_11 )
{
T_1 V_30 = 0 ;
if ( F_10 ( ! V_11 ) )
return V_11 ;
F_11 ( & V_3 -> V_31 ) ;
while ( V_11 ) {
T_1 V_17 ;
V_17 = F_2 ( V_3 , V_10 , V_29 , V_11 ) ;
if ( V_17 <= 0 ) {
if ( V_30 == 0 )
V_30 = V_17 ;
break;
}
V_10 += V_17 ;
V_29 += V_17 ;
V_11 -= V_17 ;
V_30 += V_17 ;
}
F_12 ( & V_3 -> V_31 ) ;
return V_30 ;
}
static T_1 F_13 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_10 , T_4 V_29 , T_2 V_11 )
{
struct V_2 * V_3 ;
V_3 = F_14 ( F_15 ( V_35 , struct V_38 , V_35 ) ) ;
return F_9 ( V_3 , V_10 , V_29 , V_11 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , const char * V_10 ,
unsigned V_4 , T_2 V_11 )
{
struct V_1 * V_9 ;
struct V_12 V_13 ;
T_1 V_17 = 0 ;
unsigned long V_15 , V_39 ;
unsigned V_40 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_3 -> V_41 )
V_11 = V_3 -> V_41 ;
V_40 = F_17 ( V_4 + 1 , V_3 -> V_6 . V_42 ) ;
if ( V_4 + V_11 > V_40 )
V_11 = V_40 - V_4 ;
if ( ! V_3 -> V_19 ) {
int V_5 = 0 ;
V_13 . V_21 = V_9 -> V_21 ;
V_13 . V_7 = 0 ;
V_13 . V_10 = V_3 -> V_43 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_13 . V_10 [ V_5 ++ ] = V_4 >> 8 ;
V_13 . V_10 [ V_5 ++ ] = V_4 ;
memcpy ( & V_13 . V_10 [ V_5 ] , V_10 , V_11 ) ;
V_13 . V_22 = V_5 + V_11 ;
}
V_15 = V_24 + F_3 ( V_25 ) ;
do {
V_39 = V_24 ;
if ( V_3 -> V_44 ) {
switch ( V_3 -> V_44 ) {
case V_45 :
V_17 = F_18 ( V_9 ,
V_4 , V_11 , V_10 ) ;
break;
case V_46 :
V_17 = F_19 ( V_9 ,
V_4 , V_10 [ 0 ] ) ;
break;
}
if ( V_17 == 0 )
V_17 = V_11 ;
} else {
V_17 = F_5 ( V_9 -> V_26 , & V_13 , 1 ) ;
if ( V_17 == 1 )
V_17 = V_11 ;
}
F_6 ( & V_9 -> V_27 , L_2 ,
V_11 , V_4 , V_17 , V_24 ) ;
if ( V_17 == V_11 )
return V_11 ;
F_7 ( 1 ) ;
} while ( F_8 ( V_39 , V_15 ) );
return - V_28 ;
}
static T_1 F_20 ( struct V_2 * V_3 , const char * V_10 , T_4 V_29 ,
T_2 V_11 )
{
T_1 V_30 = 0 ;
if ( F_10 ( ! V_11 ) )
return V_11 ;
F_11 ( & V_3 -> V_31 ) ;
while ( V_11 ) {
T_1 V_17 ;
V_17 = F_16 ( V_3 , V_10 , V_29 , V_11 ) ;
if ( V_17 <= 0 ) {
if ( V_30 == 0 )
V_30 = V_17 ;
break;
}
V_10 += V_17 ;
V_29 += V_17 ;
V_11 -= V_17 ;
V_30 += V_17 ;
}
F_12 ( & V_3 -> V_31 ) ;
return V_30 ;
}
static T_1 F_21 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_10 , T_4 V_29 , T_2 V_11 )
{
struct V_2 * V_3 ;
V_3 = F_14 ( F_15 ( V_35 , struct V_38 , V_35 ) ) ;
return F_20 ( V_3 , V_10 , V_29 , V_11 ) ;
}
static T_1 F_22 ( struct V_47 * V_48 , char * V_10 ,
T_5 V_4 , T_2 V_11 )
{
struct V_2 * V_3 = F_15 ( V_48 , struct V_2 , V_48 ) ;
return F_9 ( V_3 , V_10 , V_4 , V_11 ) ;
}
static T_1 F_23 ( struct V_47 * V_48 , const char * V_10 ,
T_5 V_4 , T_2 V_11 )
{
struct V_2 * V_3 = F_15 ( V_48 , struct V_2 , V_48 ) ;
return F_20 ( V_3 , V_10 , V_4 , V_11 ) ;
}
static void F_24 ( struct V_1 * V_9 ,
struct V_49 * V_6 )
{
const T_6 * V_50 ;
struct V_51 * V_52 = V_9 -> V_27 . V_53 ;
if ( V_52 ) {
if ( F_25 ( V_52 , L_3 , NULL ) )
V_6 -> V_7 |= V_54 ;
V_50 = F_25 ( V_52 , L_4 , NULL ) ;
if ( V_50 )
V_6 -> V_42 = F_26 ( V_50 ) ;
}
}
static void F_24 ( struct V_1 * V_9 ,
struct V_49 * V_6 )
{ }
static int F_27 ( struct V_1 * V_9 , const struct V_55 * V_56 )
{
struct V_49 V_6 ;
T_7 V_57 = 0 ;
bool V_58 ;
int V_19 = 0 ;
int V_44 = 0 ;
struct V_2 * V_3 ;
int V_59 ;
unsigned V_5 , V_60 ;
if ( V_9 -> V_27 . V_61 ) {
V_6 = * (struct V_49 * ) V_9 -> V_27 . V_61 ;
} else {
if ( V_56 ) {
V_57 = V_56 -> V_62 ;
} else {
const struct V_63 * V_64 ;
V_64 = F_28 ( V_65 , & V_9 -> V_27 ) ;
if ( V_64 )
V_57 = V_64 -> V_62 ;
}
if ( ! V_57 )
return - V_66 ;
V_6 . V_67 = F_29 ( V_57 & F_30 ( V_68 ) ) ;
V_57 >>= V_68 ;
V_6 . V_7 = V_57 & F_30 ( V_69 ) ;
V_6 . V_42 = 1 ;
F_24 ( V_9 , & V_6 ) ;
V_6 . V_70 = NULL ;
V_6 . V_71 = NULL ;
}
if ( ! F_31 ( V_6 . V_67 ) )
F_32 ( & V_9 -> V_27 ,
L_5 ) ;
if ( ! V_6 . V_42 ) {
F_33 ( & V_9 -> V_27 , L_6 ) ;
return - V_72 ;
}
if ( ! F_31 ( V_6 . V_42 ) )
F_32 ( & V_9 -> V_27 ,
L_7 ) ;
if ( ! F_34 ( V_9 -> V_26 , V_73 ) ) {
if ( V_6 . V_7 & V_8 )
return - V_74 ;
if ( F_34 ( V_9 -> V_26 ,
V_75 ) ) {
V_19 = V_45 ;
} else if ( F_34 ( V_9 -> V_26 ,
V_76 ) ) {
V_19 = V_77 ;
} else if ( F_34 ( V_9 -> V_26 ,
V_78 ) ) {
V_19 = V_46 ;
} else {
return - V_74 ;
}
}
if ( ! F_34 ( V_9 -> V_26 , V_73 ) ) {
if ( F_34 ( V_9 -> V_26 ,
V_79 ) ) {
V_44 = V_45 ;
} else if ( F_34 ( V_9 -> V_26 ,
V_80 ) ) {
V_44 = V_46 ;
V_6 . V_42 = 1 ;
}
}
if ( V_6 . V_7 & V_81 )
V_60 = 8 ;
else
V_60 = F_35 ( V_6 . V_67 ,
( V_6 . V_7 & V_8 ) ? 65536 : 256 ) ;
V_3 = F_36 ( & V_9 -> V_27 , sizeof( struct V_2 ) +
V_60 * sizeof( struct V_1 * ) , V_82 ) ;
if ( ! V_3 )
return - V_83 ;
F_37 ( & V_3 -> V_31 ) ;
V_3 -> V_19 = V_19 ;
V_3 -> V_44 = V_44 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_60 = V_60 ;
F_38 ( & V_3 -> V_84 ) ;
V_3 -> V_84 . V_37 . V_85 = L_8 ;
V_3 -> V_84 . V_37 . V_86 = V_6 . V_7 & V_87 ? V_88 : V_89 ;
V_3 -> V_84 . V_90 = F_13 ;
V_3 -> V_84 . V_91 = V_6 . V_67 ;
V_3 -> V_48 . V_90 = F_22 ;
V_58 = ! ( V_6 . V_7 & V_54 ) ;
if ( V_58 ) {
if ( ! V_19 || V_44 ) {
unsigned V_41 = V_6 . V_42 ;
V_3 -> V_48 . V_92 = F_23 ;
V_3 -> V_84 . V_92 = F_21 ;
V_3 -> V_84 . V_37 . V_86 |= V_93 ;
if ( V_41 > V_18 )
V_41 = V_18 ;
if ( V_19 && V_41 > V_20 )
V_41 = V_20 ;
V_3 -> V_41 = V_41 ;
V_3 -> V_43 = F_36 ( & V_9 -> V_27 ,
V_41 + 2 , V_82 ) ;
if ( ! V_3 -> V_43 )
return - V_83 ;
} else {
F_32 ( & V_9 -> V_27 ,
L_9 ) ;
}
}
V_3 -> V_9 [ 0 ] = V_9 ;
for ( V_5 = 1 ; V_5 < V_60 ; V_5 ++ ) {
V_3 -> V_9 [ V_5 ] = F_39 ( V_9 -> V_26 ,
V_9 -> V_21 + V_5 ) ;
if ( ! V_3 -> V_9 [ V_5 ] ) {
F_33 ( & V_9 -> V_27 , L_10 ,
V_9 -> V_21 + V_5 ) ;
V_59 = - V_94 ;
goto V_95;
}
}
V_59 = F_40 ( & V_9 -> V_27 . V_35 , & V_3 -> V_84 ) ;
if ( V_59 )
goto V_95;
F_41 ( V_9 , V_3 ) ;
F_42 ( & V_9 -> V_27 , L_11 ,
V_3 -> V_84 . V_91 , V_9 -> V_85 ,
V_58 ? L_12 : L_3 , V_3 -> V_41 ) ;
if ( V_19 == V_77 ||
V_19 == V_46 ) {
F_43 ( & V_9 -> V_27 , L_13
L_14 , V_19 ==
V_77 ? L_15 : L_16 ) ;
}
if ( V_6 . V_70 )
V_6 . V_70 ( & V_3 -> V_48 , V_6 . V_71 ) ;
return 0 ;
V_95:
for ( V_5 = 1 ; V_5 < V_60 ; V_5 ++ )
if ( V_3 -> V_9 [ V_5 ] )
F_44 ( V_3 -> V_9 [ V_5 ] ) ;
return V_59 ;
}
static int F_45 ( struct V_1 * V_9 )
{
struct V_2 * V_3 ;
int V_5 ;
V_3 = F_46 ( V_9 ) ;
F_47 ( & V_9 -> V_27 . V_35 , & V_3 -> V_84 ) ;
for ( V_5 = 1 ; V_5 < V_3 -> V_60 ; V_5 ++ )
F_44 ( V_3 -> V_9 [ V_5 ] ) ;
return 0 ;
}
static int T_8 F_48 ( void )
{
if ( ! V_18 ) {
F_49 ( L_17 ) ;
return - V_72 ;
}
V_18 = F_50 ( V_18 ) ;
return F_51 ( & V_96 ) ;
}
static void T_9 F_52 ( void )
{
F_53 ( & V_96 ) ;
}
