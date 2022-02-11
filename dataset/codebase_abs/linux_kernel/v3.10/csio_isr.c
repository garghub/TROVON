static T_1
F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
int V_5 ;
unsigned long V_6 ;
if ( F_2 ( ! V_4 ) )
return V_7 ;
if ( F_2 ( F_3 ( V_4 -> V_8 ) ) ) {
F_4 ( V_4 , V_9 ) ;
return V_7 ;
}
F_5 ( & V_4 -> V_10 , V_6 ) ;
F_6 ( V_4 ) ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 == 0 && ! ( V_4 -> V_6 & V_11 ) ) {
V_4 -> V_6 |= V_11 ;
F_8 ( & V_4 -> V_10 , V_6 ) ;
F_9 ( & V_4 -> V_12 ) ;
return V_13 ;
}
F_8 ( & V_4 -> V_10 , V_6 ) ;
return V_13 ;
}
static void
F_10 ( struct V_3 * V_4 )
{
int V_5 ;
unsigned long V_6 ;
V_5 = F_11 ( V_4 ) ;
F_5 ( & V_4 -> V_10 , V_6 ) ;
if ( V_5 == 0 && ! ( V_4 -> V_6 & V_11 ) ) {
V_4 -> V_6 |= V_11 ;
F_8 ( & V_4 -> V_10 , V_6 ) ;
F_9 ( & V_4 -> V_12 ) ;
return;
}
F_8 ( & V_4 -> V_10 , V_6 ) ;
}
static T_1
F_12 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( F_2 ( ! V_4 ) )
return V_7 ;
if ( F_2 ( F_3 ( V_4 -> V_8 ) ) ) {
F_4 ( V_4 , V_9 ) ;
return V_7 ;
}
F_10 ( V_4 ) ;
return V_13 ;
}
void
F_13 ( struct V_3 * V_4 , void * V_14 , T_2 V_15 ,
struct V_16 * V_17 , void * V_18 )
{
F_10 ( V_4 ) ;
}
static void
F_14 ( struct V_3 * V_4 , void * V_14 , T_2 V_15 ,
struct V_16 * V_17 , void * V_19 )
{
struct V_20 * V_21 ;
T_3 * V_22 ;
T_3 V_23 ;
void * V_24 ;
unsigned long V_6 ;
V_21 = F_15 ( V_4 , V_14 , V_15 , V_17 , NULL , & V_22 ) ;
if ( F_16 ( V_21 ) ) {
if ( F_2 ( * V_22 == V_25 ) ) {
V_23 = F_17 (
( (struct V_26 * )
V_22 ) -> V_27 ) ;
F_18 ( V_4 , L_1 ,
V_23 ? L_2 : L_3 ,
V_21 , V_21 -> V_28 ) ;
F_5 ( & V_4 -> V_10 , V_6 ) ;
if ( V_23 )
F_19 ( V_21 ,
(struct V_29 * ) V_19 ) ;
else
F_20 ( V_21 ,
(struct V_29 * ) V_19 ) ;
V_24 = F_21 ( V_21 ) ;
if ( F_2 ( V_24 == NULL ) )
F_22 ( & V_21 -> V_30 . V_31 ) ;
F_8 ( & V_4 -> V_10 , V_6 ) ;
if ( F_2 ( V_24 == NULL ) )
F_23 ( V_4 ,
F_24 ( V_4 ) , V_21 ) ;
} else {
F_5 ( & V_4 -> V_10 , V_6 ) ;
F_25 ( V_21 , (struct V_29 * ) V_19 ) ;
F_8 ( & V_4 -> V_10 , V_6 ) ;
}
}
}
static inline T_1
F_26 ( struct V_32 * V_33 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 -> V_34 ;
F_27 ( V_19 ) ;
struct V_29 * V_35 ;
struct V_36 * V_37 ;
struct V_20 * V_21 ;
int V_38 = 0 ;
V_37 = F_24 ( V_4 ) ;
if ( F_2 ( F_28 ( V_4 , V_33 , F_14 ,
& V_19 ) != 0 ) )
return V_7 ;
F_29 (tmp, &cbfn_q) {
V_21 = (struct V_20 * ) V_35 ;
V_38 ++ ;
V_21 -> V_39 ( V_4 , V_21 ) ;
if ( F_2 ( V_21 -> V_40 ) )
F_30 ( V_4 , V_37 , & V_21 -> V_41 ,
V_21 -> V_42 ) ;
}
if ( V_38 ) {
F_31 ( V_4 , V_37 , & V_19 ,
V_38 ) ;
}
return V_13 ;
}
static T_1
F_32 ( int V_1 , void * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 ;
struct V_3 * V_4 ;
if ( F_2 ( ! V_33 ) )
return V_7 ;
V_4 = (struct V_3 * ) V_33 -> V_34 ;
if ( F_2 ( F_3 ( V_4 -> V_8 ) ) ) {
F_4 ( V_4 , V_9 ) ;
return V_7 ;
}
F_26 ( V_33 ) ;
return V_13 ;
}
void
F_33 ( struct V_3 * V_4 , void * V_14 , T_2 V_15 ,
struct V_16 * V_17 , void * V_18 )
{
struct V_32 * V_33 = V_18 ;
F_26 ( V_33 ) ;
}
static T_1
F_34 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_32 * V_43 = NULL ;
int V_5 ;
T_1 V_44 = V_7 ;
unsigned long V_6 ;
if ( F_2 ( ! V_4 ) )
return V_7 ;
if ( F_2 ( F_3 ( V_4 -> V_8 ) ) ) {
F_4 ( V_4 , V_9 ) ;
return V_7 ;
}
if ( V_4 -> V_45 == V_46 )
F_35 ( V_4 , 0 , F_36 ( V_47 ) ) ;
if ( F_6 ( V_4 ) )
V_44 = V_13 ;
V_43 = F_37 ( V_4 , V_4 -> V_48 ) ;
F_38 ( V_43 ) ;
if ( F_16 ( F_28 ( V_4 , V_43 , NULL , NULL ) == 0 ) )
V_44 = V_13 ;
F_5 ( & V_4 -> V_10 , V_6 ) ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 == 0 && ! ( V_4 -> V_6 & V_11 ) ) {
V_4 -> V_6 |= V_11 ;
F_8 ( & V_4 -> V_10 , V_6 ) ;
F_9 ( & V_4 -> V_12 ) ;
return V_13 ;
}
F_8 ( & V_4 -> V_10 , V_6 ) ;
return V_44 ;
}
static void
F_39 ( struct V_3 * V_4 )
{
int V_49 ;
struct V_50 * V_51 = & V_4 -> V_52 [ 0 ] ;
int V_53 = V_54 ;
int V_15 = sizeof( V_51 -> V_55 ) - 1 ;
int V_56 = V_4 -> V_57 + V_53 ;
memset ( V_51 -> V_55 , 0 , V_15 + 1 ) ;
snprintf ( V_51 -> V_55 , V_15 , L_4 ,
F_40 ( V_4 ) , F_41 ( V_4 ) , F_42 ( V_4 ) ) ;
V_51 ++ ;
memset ( V_51 -> V_55 , 0 , V_15 + 1 ) ;
snprintf ( V_51 -> V_55 , V_15 , L_5 ,
F_40 ( V_4 ) , F_41 ( V_4 ) , F_42 ( V_4 ) ) ;
V_51 ++ ;
for ( V_49 = V_53 ; V_49 < V_56 ; V_49 ++ , V_51 ++ ) {
memset ( V_51 -> V_55 , 0 , V_15 + 1 ) ;
snprintf ( V_51 -> V_55 , V_15 , L_6 ,
F_40 ( V_4 ) , F_41 ( V_4 ) ,
F_42 ( V_4 ) , V_49 - V_54 ) ;
}
}
int
F_43 ( struct V_3 * V_4 )
{
int V_5 , V_49 , V_58 , V_53 = 0 ;
struct V_50 * V_51 = & V_4 -> V_52 [ 0 ] ;
struct V_59 * V_60 ;
if ( V_4 -> V_45 != V_61 ) {
V_5 = F_44 ( V_4 -> V_8 -> V_1 , F_34 ,
( V_4 -> V_45 == V_62 ) ?
0 : V_63 ,
V_64 , V_4 ) ;
if ( V_5 ) {
if ( V_4 -> V_45 == V_62 )
F_45 ( V_4 -> V_8 ) ;
F_46 ( V_4 , L_7 ) ;
return - V_65 ;
}
goto V_66;
}
F_39 ( V_4 ) ;
V_5 = F_44 ( V_51 [ V_53 ] . V_67 , F_1 , 0 ,
V_51 [ V_53 ] . V_55 , V_4 ) ;
if ( V_5 ) {
F_46 ( V_4 , L_8 ,
V_51 [ V_53 ] . V_67 , V_5 ) ;
goto V_68;
}
V_51 [ V_53 ++ ] . V_2 = ( void * ) V_4 ;
V_5 = F_44 ( V_51 [ V_53 ] . V_67 , F_12 , 0 ,
V_51 [ V_53 ] . V_55 , V_4 ) ;
if ( V_5 ) {
F_46 ( V_4 , L_8 ,
V_51 [ V_53 ] . V_67 , V_5 ) ;
goto V_68;
}
V_51 [ V_53 ++ ] . V_2 = ( void * ) V_4 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_69 ; V_49 ++ ) {
V_60 = & V_4 -> V_70 [ V_49 ] ;
for ( V_58 = 0 ; V_58 < V_60 -> V_71 ; V_58 ++ , V_53 ++ ) {
struct V_72 * V_73 = & V_4 -> V_73 [ V_49 ] [ V_58 ] ;
struct V_32 * V_74 = V_4 -> V_75 . V_76 [ V_73 -> V_77 ] ;
V_5 = F_44 ( V_51 [ V_53 ] . V_67 , F_32 , 0 ,
V_51 [ V_53 ] . V_55 , V_74 ) ;
if ( V_5 ) {
F_46 ( V_4 ,
L_8 ,
V_51 [ V_53 ] . V_67 , V_5 ) ;
goto V_68;
}
V_51 [ V_53 ] . V_2 = ( void * ) V_74 ;
}
}
V_66:
V_4 -> V_6 |= V_78 ;
return 0 ;
V_68:
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
V_51 = & V_4 -> V_52 [ V_49 ] ;
F_47 ( V_51 -> V_67 , V_51 -> V_2 ) ;
}
F_48 ( V_4 -> V_8 ) ;
return - V_65 ;
}
static void
F_49 ( struct V_3 * V_4 , bool free )
{
int V_49 ;
struct V_50 * V_51 ;
int V_56 = V_4 -> V_57 + V_54 ;
if ( free ) {
for ( V_49 = 0 ; V_49 < V_56 ; V_49 ++ ) {
V_51 = & V_4 -> V_52 [ V_49 ] ;
F_47 ( V_51 -> V_67 , V_51 -> V_2 ) ;
}
}
F_48 ( V_4 -> V_8 ) ;
}
static void
F_50 ( struct V_3 * V_4 , int V_56 )
{
int V_49 ;
struct V_59 * V_60 ;
while ( V_56 < V_4 -> V_57 ) {
for ( V_49 = 0 ; V_49 < V_4 -> V_69 ; V_49 ++ ) {
V_60 = & V_4 -> V_70 [ V_49 ] ;
if ( V_60 -> V_71 > 1 ) {
V_60 -> V_71 -- ;
V_4 -> V_57 -- ;
if ( V_4 -> V_57 <= V_56 )
break;
}
}
}
F_18 ( V_4 , L_9 , V_4 -> V_57 ) ;
}
static int
F_51 ( struct V_3 * V_4 )
{
int V_5 , V_49 , V_58 , V_53 , V_79 , V_80 , V_56 ;
struct V_50 * V_51 ;
struct V_81 * V_82 ;
int V_83 = V_54 ;
struct V_59 * V_60 ;
V_80 = V_4 -> V_69 + V_83 ;
V_56 = V_4 -> V_57 + V_83 ;
if ( V_4 -> V_6 & V_84 || ! F_52 ( V_4 ) )
V_56 = F_53 ( T_3 , V_4 -> V_85 , V_56 ) ;
V_82 = F_54 ( sizeof( struct V_81 ) * V_56 , V_86 ) ;
if ( ! V_82 )
return - V_87 ;
for ( V_49 = 0 ; V_49 < V_56 ; V_49 ++ )
V_82 [ V_49 ] . V_88 = ( V_89 ) V_49 ;
F_18 ( V_4 , L_10 , V_4 -> V_85 , V_56 ) ;
while ( ( V_5 = F_55 ( V_4 -> V_8 , V_82 , V_56 ) ) >= V_80 )
V_56 = V_5 ;
if ( ! V_5 ) {
if ( V_56 < ( V_4 -> V_57 + V_83 ) ) {
F_18 ( V_4 , L_11 , V_56 - V_83 ) ;
F_50 ( V_4 , V_56 - V_83 ) ;
}
} else {
if ( V_5 > 0 ) {
F_48 ( V_4 -> V_8 ) ;
F_56 ( V_4 , L_12 , V_5 ) ;
}
F_57 ( V_82 ) ;
return - V_87 ;
}
for ( V_49 = 0 ; V_49 < V_56 ; V_49 ++ ) {
V_51 = & V_4 -> V_52 [ V_49 ] ;
V_51 -> V_67 = V_82 [ V_49 ] . V_67 ;
}
V_53 = 0 ;
F_58 ( V_4 , V_82 [ V_53 ] . V_88 ) ;
F_59 ( F_60 ( V_4 ) , V_82 [ V_53 ++ ] . V_88 ) ;
F_61 ( V_4 , V_82 [ V_53 ++ ] . V_88 ) ;
for ( V_49 = 0 ; V_49 < V_4 -> V_69 ; V_49 ++ ) {
V_60 = & V_4 -> V_70 [ V_49 ] ;
for ( V_58 = 0 ; V_58 < V_4 -> V_90 ; V_58 ++ ) {
V_79 = ( V_58 % V_60 -> V_71 ) + V_53 ;
V_4 -> V_73 [ V_49 ] [ V_58 ] . V_91 = V_82 [ V_79 ] . V_88 ;
}
V_53 += V_60 -> V_71 ;
}
F_57 ( V_82 ) ;
return 0 ;
}
void
F_62 ( struct V_3 * V_4 )
{
V_4 -> V_45 = V_92 ;
V_4 -> V_6 &= ~ V_78 ;
if ( ( V_93 == 2 ) && ! F_51 ( V_4 ) )
V_4 -> V_45 = V_61 ;
else {
if ( V_4 -> V_6 & V_84 ||
! F_52 ( V_4 ) ) {
int V_83 = V_94 ;
if ( V_4 -> V_85 < ( V_4 -> V_57 + V_83 ) ) {
F_18 ( V_4 , L_11 ,
V_4 -> V_85 - V_83 ) ;
F_50 ( V_4 , V_4 -> V_85 - V_83 ) ;
}
}
if ( ( V_93 == 1 ) && ! F_63 ( V_4 -> V_8 ) )
V_4 -> V_45 = V_62 ;
else
V_4 -> V_45 = V_46 ;
}
F_18 ( V_4 , L_13 ,
( V_4 -> V_45 == V_61 ) ? L_14 :
( ( V_4 -> V_45 == V_62 ) ? L_15 : L_16 ) ) ;
}
void
F_64 ( struct V_3 * V_4 , bool free )
{
F_65 ( V_4 ) ;
switch ( V_4 -> V_45 ) {
case V_61 :
F_49 ( V_4 , free ) ;
break;
case V_62 :
if ( free )
F_47 ( V_4 -> V_8 -> V_1 , V_4 ) ;
F_45 ( V_4 -> V_8 ) ;
break;
case V_46 :
if ( free )
F_47 ( V_4 -> V_8 -> V_1 , V_4 ) ;
break;
default:
break;
}
V_4 -> V_45 = V_92 ;
V_4 -> V_6 &= ~ V_78 ;
}
