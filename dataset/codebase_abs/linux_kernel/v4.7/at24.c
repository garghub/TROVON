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
F_7 ( 1000 , 1500 ) ;
} while ( F_8 ( V_16 , V_15 ) );
return - V_28 ;
}
static int F_9 ( void * V_29 , unsigned int V_30 , void * V_31 , T_2 V_11 )
{
struct V_2 * V_3 = V_29 ;
char * V_10 = V_31 ;
if ( F_10 ( ! V_11 ) )
return V_11 ;
F_11 ( & V_3 -> V_32 ) ;
while ( V_11 ) {
int V_17 ;
V_17 = F_2 ( V_3 , V_10 , V_30 , V_11 ) ;
if ( V_17 < 0 ) {
F_12 ( & V_3 -> V_32 ) ;
return V_17 ;
}
V_10 += V_17 ;
V_30 += V_17 ;
V_11 -= V_17 ;
}
F_12 ( & V_3 -> V_32 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_2 * V_3 , const char * V_10 ,
unsigned V_4 , T_2 V_11 )
{
struct V_1 * V_9 ;
struct V_12 V_13 ;
T_1 V_17 = 0 ;
unsigned long V_15 , V_33 ;
unsigned V_34 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_3 -> V_35 )
V_11 = V_3 -> V_35 ;
V_34 = F_14 ( V_4 + 1 , V_3 -> V_6 . V_36 ) ;
if ( V_4 + V_11 > V_34 )
V_11 = V_34 - V_4 ;
if ( ! V_3 -> V_19 ) {
int V_5 = 0 ;
V_13 . V_21 = V_9 -> V_21 ;
V_13 . V_7 = 0 ;
V_13 . V_10 = V_3 -> V_37 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_13 . V_10 [ V_5 ++ ] = V_4 >> 8 ;
V_13 . V_10 [ V_5 ++ ] = V_4 ;
memcpy ( & V_13 . V_10 [ V_5 ] , V_10 , V_11 ) ;
V_13 . V_22 = V_5 + V_11 ;
}
V_15 = V_24 + F_3 ( V_25 ) ;
do {
V_33 = V_24 ;
if ( V_3 -> V_38 ) {
switch ( V_3 -> V_38 ) {
case V_39 :
V_17 = F_15 ( V_9 ,
V_4 , V_11 , V_10 ) ;
break;
case V_40 :
V_17 = F_16 ( V_9 ,
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
F_7 ( 1000 , 1500 ) ;
} while ( F_8 ( V_33 , V_15 ) );
return - V_28 ;
}
static int F_17 ( void * V_29 , unsigned int V_30 , void * V_31 , T_2 V_11 )
{
struct V_2 * V_3 = V_29 ;
char * V_10 = V_31 ;
if ( F_10 ( ! V_11 ) )
return - V_41 ;
F_11 ( & V_3 -> V_32 ) ;
while ( V_11 ) {
int V_17 ;
V_17 = F_13 ( V_3 , V_10 , V_30 , V_11 ) ;
if ( V_17 < 0 ) {
F_12 ( & V_3 -> V_32 ) ;
return V_17 ;
}
V_10 += V_17 ;
V_30 += V_17 ;
V_11 -= V_17 ;
}
F_12 ( & V_3 -> V_32 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_9 ,
struct V_42 * V_6 )
{
const T_4 * V_31 ;
struct V_43 * V_44 = V_9 -> V_27 . V_45 ;
if ( V_44 ) {
if ( F_19 ( V_44 , L_3 , NULL ) )
V_6 -> V_7 |= V_46 ;
V_31 = F_19 ( V_44 , L_4 , NULL ) ;
if ( V_31 )
V_6 -> V_36 = F_20 ( V_31 ) ;
}
}
static void F_18 ( struct V_1 * V_9 ,
struct V_42 * V_6 )
{ }
static int F_21 ( struct V_1 * V_9 , const struct V_47 * V_48 )
{
struct V_42 V_6 ;
T_5 V_49 = 0 ;
bool V_50 ;
int V_19 = 0 ;
int V_38 = 0 ;
struct V_2 * V_3 ;
int V_51 ;
unsigned V_5 , V_52 ;
if ( V_9 -> V_27 . V_53 ) {
V_6 = * (struct V_42 * ) V_9 -> V_27 . V_53 ;
} else {
if ( V_48 ) {
V_49 = V_48 -> V_54 ;
} else {
const struct V_55 * V_56 ;
V_56 = F_22 ( V_57 , & V_9 -> V_27 ) ;
if ( V_56 )
V_49 = V_56 -> V_54 ;
}
if ( ! V_49 )
return - V_58 ;
V_6 . V_59 = F_23 ( V_49 & F_24 ( V_60 ) ) ;
V_49 >>= V_60 ;
V_6 . V_7 = V_49 & F_24 ( V_61 ) ;
V_6 . V_36 = 1 ;
F_18 ( V_9 , & V_6 ) ;
V_6 . V_62 = NULL ;
V_6 . V_63 = NULL ;
}
if ( ! F_25 ( V_6 . V_59 ) )
F_26 ( & V_9 -> V_27 ,
L_5 ) ;
if ( ! V_6 . V_36 ) {
F_27 ( & V_9 -> V_27 , L_6 ) ;
return - V_41 ;
}
if ( ! F_25 ( V_6 . V_36 ) )
F_26 ( & V_9 -> V_27 ,
L_7 ) ;
if ( ! F_28 ( V_9 -> V_26 , V_64 ) ) {
if ( V_6 . V_7 & V_8 )
return - V_65 ;
if ( F_28 ( V_9 -> V_26 ,
V_66 ) ) {
V_19 = V_39 ;
} else if ( F_28 ( V_9 -> V_26 ,
V_67 ) ) {
V_19 = V_68 ;
} else if ( F_28 ( V_9 -> V_26 ,
V_69 ) ) {
V_19 = V_40 ;
} else {
return - V_65 ;
}
if ( F_28 ( V_9 -> V_26 ,
V_70 ) ) {
V_38 = V_39 ;
} else if ( F_28 ( V_9 -> V_26 ,
V_71 ) ) {
V_38 = V_40 ;
V_6 . V_36 = 1 ;
}
}
if ( V_6 . V_7 & V_72 )
V_52 = 8 ;
else
V_52 = F_29 ( V_6 . V_59 ,
( V_6 . V_7 & V_8 ) ? 65536 : 256 ) ;
V_3 = F_30 ( & V_9 -> V_27 , sizeof( struct V_2 ) +
V_52 * sizeof( struct V_1 * ) , V_73 ) ;
if ( ! V_3 )
return - V_74 ;
F_31 ( & V_3 -> V_32 ) ;
V_3 -> V_19 = V_19 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_52 = V_52 ;
V_50 = ! ( V_6 . V_7 & V_46 ) ;
if ( V_50 ) {
if ( ! V_19 || V_38 ) {
unsigned V_35 = V_6 . V_36 ;
if ( V_35 > V_18 )
V_35 = V_18 ;
if ( V_19 && V_35 > V_20 )
V_35 = V_20 ;
V_3 -> V_35 = V_35 ;
V_3 -> V_37 = F_30 ( & V_9 -> V_27 ,
V_35 + 2 , V_73 ) ;
if ( ! V_3 -> V_37 )
return - V_74 ;
} else {
F_26 ( & V_9 -> V_27 ,
L_8 ) ;
}
}
V_3 -> V_9 [ 0 ] = V_9 ;
for ( V_5 = 1 ; V_5 < V_52 ; V_5 ++ ) {
V_3 -> V_9 [ V_5 ] = F_32 ( V_9 -> V_26 ,
V_9 -> V_21 + V_5 ) ;
if ( ! V_3 -> V_9 [ V_5 ] ) {
F_27 ( & V_9 -> V_27 , L_9 ,
V_9 -> V_21 + V_5 ) ;
V_51 = - V_75 ;
goto V_76;
}
}
V_3 -> V_77 . V_78 = F_33 ( & V_9 -> V_27 ) ;
V_3 -> V_77 . V_27 = & V_9 -> V_27 ;
V_3 -> V_77 . V_79 = ! V_50 ;
V_3 -> V_77 . V_80 = true ;
V_3 -> V_77 . V_81 = V_82 ;
V_3 -> V_77 . V_83 = true ;
V_3 -> V_77 . V_84 = & V_9 -> V_27 ;
V_3 -> V_77 . V_85 = F_9 ;
V_3 -> V_77 . V_86 = F_17 ;
V_3 -> V_77 . V_29 = V_3 ;
V_3 -> V_77 . V_87 = 4 ;
V_3 -> V_77 . V_88 = 1 ;
V_3 -> V_77 . V_89 = V_6 . V_59 ;
V_3 -> V_90 = F_34 ( & V_3 -> V_77 ) ;
if ( F_35 ( V_3 -> V_90 ) ) {
V_51 = F_36 ( V_3 -> V_90 ) ;
goto V_76;
}
F_37 ( V_9 , V_3 ) ;
F_38 ( & V_9 -> V_27 , L_10 ,
V_6 . V_59 , V_9 -> V_78 ,
V_50 ? L_11 : L_3 , V_3 -> V_35 ) ;
if ( V_19 == V_68 ||
V_19 == V_40 ) {
F_39 ( & V_9 -> V_27 , L_12
L_13 , V_19 ==
V_68 ? L_14 : L_15 ) ;
}
if ( V_6 . V_62 )
V_6 . V_62 ( V_3 -> V_90 , V_6 . V_63 ) ;
return 0 ;
V_76:
for ( V_5 = 1 ; V_5 < V_52 ; V_5 ++ )
if ( V_3 -> V_9 [ V_5 ] )
F_40 ( V_3 -> V_9 [ V_5 ] ) ;
return V_51 ;
}
static int F_41 ( struct V_1 * V_9 )
{
struct V_2 * V_3 ;
int V_5 ;
V_3 = F_42 ( V_9 ) ;
F_43 ( V_3 -> V_90 ) ;
for ( V_5 = 1 ; V_5 < V_3 -> V_52 ; V_5 ++ )
F_40 ( V_3 -> V_9 [ V_5 ] ) ;
return 0 ;
}
static int T_6 F_44 ( void )
{
if ( ! V_18 ) {
F_45 ( L_16 ) ;
return - V_41 ;
}
V_18 = F_46 ( V_18 ) ;
return F_47 ( & V_91 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_91 ) ;
}
