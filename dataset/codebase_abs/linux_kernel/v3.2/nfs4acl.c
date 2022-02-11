static T_1
F_1 ( unsigned short V_1 , unsigned int V_2 )
{
int V_3 = V_4 ;
if ( V_2 & V_5 )
V_3 |= V_6 ;
if ( V_1 & V_7 )
V_3 |= V_8 ;
if ( V_1 & V_9 )
V_3 |= V_10 ;
if ( ( V_1 & V_9 ) && ( V_2 & V_11 ) )
V_3 |= V_12 ;
if ( V_1 & V_13 )
V_3 |= V_14 ;
return V_3 ;
}
static T_1
F_2 ( unsigned short V_1 , T_1 V_2 )
{
T_1 V_3 = 0 ;
if ( V_1 & V_7 )
V_3 |= V_8 ;
if ( V_1 & V_9 )
V_3 |= V_10 ;
if ( ( V_1 & V_9 ) && ( V_2 & V_11 ) )
V_3 |= V_12 ;
if ( V_1 & V_13 )
V_3 |= V_14 ;
return V_3 ;
}
static void
F_3 ( T_1 V_1 , unsigned short * V_15 , unsigned int V_2 )
{
T_1 V_16 = V_10 ;
if ( V_2 & V_11 )
V_16 |= V_12 ;
* V_15 = 0 ;
if ( ( V_1 & V_8 ) == V_8 )
* V_15 |= V_7 ;
if ( ( V_1 & V_16 ) == V_16 )
* V_15 |= V_9 ;
if ( ( V_1 & V_14 ) == V_14 )
* V_15 |= V_13 ;
}
struct V_17 *
F_4 ( struct V_18 * V_19 , struct V_18 * V_20 ,
unsigned int V_2 )
{
struct V_17 * V_21 ;
int V_22 = 0 ;
if ( V_19 ) {
if ( F_5 ( V_19 ) < 0 )
return F_6 ( - V_23 ) ;
V_22 += 2 * V_19 -> V_24 ;
}
if ( V_20 ) {
if ( F_5 ( V_20 ) < 0 )
return F_6 ( - V_23 ) ;
V_22 += 2 * V_20 -> V_24 ;
}
V_21 = F_7 ( V_22 ) ;
if ( V_21 == NULL )
return F_6 ( - V_25 ) ;
if ( V_19 )
F_8 ( V_19 , V_21 , V_2 & ~ V_26 ) ;
if ( V_20 )
F_8 ( V_20 , V_21 , V_2 | V_26 ) ;
return V_21 ;
}
static void
F_9 ( struct V_18 * V_21 , struct V_27 * V_28 )
{
struct V_29 * V_30 , * V_31 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_3 = 07 ;
V_31 = V_21 -> V_32 + V_21 -> V_24 ;
F_10 (pa, acl, pe) {
switch ( V_30 -> V_33 ) {
case V_34 :
V_28 -> V_35 = V_30 -> V_36 ;
break;
case V_37 :
V_28 -> V_38 = V_30 -> V_36 ;
break;
case V_39 :
V_28 -> V_40 |= V_30 -> V_36 ;
break;
case V_41 :
V_28 -> V_42 |= V_30 -> V_36 ;
break;
case V_43 :
V_28 -> V_44 = V_30 -> V_36 ;
break;
case V_45 :
V_28 -> V_3 = V_30 -> V_36 ;
break;
}
}
V_28 -> V_40 &= V_28 -> V_3 ;
V_28 -> V_38 &= V_28 -> V_3 ;
V_28 -> V_42 &= V_28 -> V_3 ;
}
static void
F_8 ( struct V_18 * V_19 , struct V_17 * V_21 ,
unsigned int V_2 )
{
struct V_29 * V_30 , * V_46 ;
struct V_47 * V_48 ;
struct V_27 V_28 ;
unsigned short V_49 ;
int V_50 = ( ( V_2 & V_26 ) ?
V_51 | V_52 : 0 ) ;
F_11 ( V_19 -> V_24 < 3 ) ;
F_9 ( V_19 , & V_28 ) ;
V_30 = V_19 -> V_32 ;
V_48 = V_21 -> V_53 + V_21 -> V_54 ;
V_49 = ~ V_28 . V_35 ;
V_49 &= V_28 . V_40 | V_28 . V_38 | V_28 . V_42 | V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_59 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 , V_2 | V_5 ) ;
V_48 -> V_58 = V_59 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
while ( V_30 -> V_33 == V_39 ) {
V_49 = ~ ( V_30 -> V_36 & V_28 . V_3 ) ;
V_49 &= V_28 . V_42 | V_28 . V_38 | V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_62 = V_30 -> V_63 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 & V_28 . V_3 ,
V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_62 = V_30 -> V_63 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
}
V_46 = V_30 ;
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_28 . V_38 , V_2 ) ;
V_48 -> V_58 = V_64 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
while ( V_30 -> V_33 == V_41 ) {
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 | V_65 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 & V_28 . V_3 ,
V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_62 = V_30 -> V_63 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
}
V_30 = V_46 ;
V_49 = ~ V_28 . V_38 & V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_64 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_30 ++ ;
while ( V_30 -> V_33 == V_41 ) {
V_49 = ~ ( V_30 -> V_36 & V_28 . V_3 ) ;
V_49 &= V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 | V_65 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_62 = V_30 -> V_63 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_30 ++ ;
}
if ( V_30 -> V_33 == V_45 )
V_30 ++ ;
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 , V_2 ) ;
V_48 -> V_58 = V_66 ;
V_21 -> V_54 ++ ;
}
static void
F_12 ( struct V_18 * V_19 , int V_67 , int V_68 ) {
int V_69 = 0 , V_70 ;
struct V_29 V_71 ;
while ( ! V_69 ) {
V_69 = 1 ;
for ( V_70 = V_67 ; V_70 < V_68 ; V_70 ++ ) {
if ( V_19 -> V_32 [ V_70 ] . V_63
> V_19 -> V_32 [ V_70 + 1 ] . V_63 ) {
V_69 = 0 ;
V_71 = V_19 -> V_32 [ V_70 ] ;
V_19 -> V_32 [ V_70 ] = V_19 -> V_32 [ V_70 + 1 ] ;
V_19 -> V_32 [ V_70 + 1 ] = V_71 ;
}
}
}
}
static void
F_13 ( struct V_18 * V_19 )
{
int V_70 , V_72 ;
if ( V_19 -> V_24 <= 4 )
return;
V_70 = 1 ;
while ( V_19 -> V_32 [ V_70 ] . V_33 == V_39 )
V_70 ++ ;
F_12 ( V_19 , 1 , V_70 - 1 ) ;
F_11 ( V_19 -> V_32 [ V_70 ] . V_33 != V_37 ) ;
V_72 = ++ V_70 ;
while ( V_19 -> V_32 [ V_72 ] . V_33 == V_41 )
V_72 ++ ;
F_12 ( V_19 , V_70 , V_72 - 1 ) ;
return;
}
static int
F_14 ( struct V_73 * V_74 , int V_75 )
{
int V_76 ;
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 -> V_77 = 1 ;
V_76 = sizeof( struct V_78 )
+ V_75 * sizeof( struct V_79 ) ;
V_74 -> V_40 = F_15 ( V_76 , V_80 ) ;
if ( ! V_74 -> V_40 )
return - V_25 ;
V_74 -> V_42 = F_15 ( V_76 , V_80 ) ;
if ( ! V_74 -> V_42 ) {
F_16 ( V_74 -> V_40 ) ;
return - V_25 ;
}
return 0 ;
}
static void
F_17 ( struct V_73 * V_74 ) {
F_16 ( V_74 -> V_40 ) ;
F_16 ( V_74 -> V_42 ) ;
}
static inline void F_18 ( struct V_73 * V_74 , struct V_81 * V_82 )
{
V_74 -> V_3 . V_83 |= V_82 -> V_83 ;
}
static inline int F_19 ( T_1 V_3 , int V_84 )
{
if ( V_3 & ( V_85 | V_86 ) )
return - V_23 ;
if ( ! V_84 )
return 0 ;
if ( V_3 & ( V_87 | V_88 ) )
return - V_23 ;
return 0 ;
}
static struct V_18 *
F_20 ( struct V_73 * V_74 , unsigned int V_2 )
{
struct V_29 * V_89 ;
struct V_18 * V_19 ;
int V_90 ;
int V_70 , error = 0 ;
if ( V_74 -> V_77 && ( V_2 & V_26 ) ) {
V_19 = F_21 ( 0 , V_80 ) ;
return V_19 ? V_19 : F_6 ( - V_25 ) ;
}
V_90 = 4 + V_74 -> V_40 -> V_91 + V_74 -> V_42 -> V_91 ;
V_19 = F_21 ( V_90 , V_80 ) ;
if ( ! V_19 )
return F_6 ( - V_25 ) ;
V_89 = V_19 -> V_32 ;
V_89 -> V_33 = V_34 ;
error = F_19 ( V_74 -> V_35 . V_49 , 1 ) ;
if ( error )
goto V_92;
F_3 ( V_74 -> V_35 . V_83 , & V_89 -> V_36 , V_2 ) ;
V_89 -> V_63 = V_93 ;
for ( V_70 = 0 ; V_70 < V_74 -> V_40 -> V_91 ; V_70 ++ ) {
V_89 ++ ;
V_89 -> V_33 = V_39 ;
error = F_19 ( V_74 -> V_40 -> V_53 [ V_70 ] . V_94 . V_49 , 0 ) ;
if ( error )
goto V_92;
F_3 ( V_74 -> V_40 -> V_53 [ V_70 ] . V_94 . V_83 ,
& V_89 -> V_36 , V_2 ) ;
V_89 -> V_63 = V_74 -> V_40 -> V_53 [ V_70 ] . V_95 ;
F_18 ( V_74 , & V_74 -> V_40 -> V_53 [ V_70 ] . V_94 ) ;
}
V_89 ++ ;
V_89 -> V_33 = V_37 ;
error = F_19 ( V_74 -> V_38 . V_49 , 0 ) ;
if ( error )
goto V_92;
F_3 ( V_74 -> V_38 . V_83 , & V_89 -> V_36 , V_2 ) ;
V_89 -> V_63 = V_93 ;
F_18 ( V_74 , & V_74 -> V_38 ) ;
for ( V_70 = 0 ; V_70 < V_74 -> V_42 -> V_91 ; V_70 ++ ) {
V_89 ++ ;
V_89 -> V_33 = V_41 ;
error = F_19 ( V_74 -> V_42 -> V_53 [ V_70 ] . V_94 . V_49 , 0 ) ;
if ( error )
goto V_92;
F_3 ( V_74 -> V_42 -> V_53 [ V_70 ] . V_94 . V_83 ,
& V_89 -> V_36 , V_2 ) ;
V_89 -> V_63 = V_74 -> V_42 -> V_53 [ V_70 ] . V_95 ;
F_18 ( V_74 , & V_74 -> V_42 -> V_53 [ V_70 ] . V_94 ) ;
}
V_89 ++ ;
V_89 -> V_33 = V_45 ;
F_3 ( V_74 -> V_3 . V_83 , & V_89 -> V_36 , V_2 ) ;
V_89 -> V_63 = V_93 ;
V_89 ++ ;
V_89 -> V_33 = V_43 ;
error = F_19 ( V_74 -> V_44 . V_49 , 0 ) ;
if ( error )
goto V_92;
F_3 ( V_74 -> V_44 . V_83 , & V_89 -> V_36 , V_2 ) ;
V_89 -> V_63 = V_93 ;
return V_19 ;
V_92:
F_22 ( V_19 ) ;
return F_6 ( error ) ;
}
static inline void F_23 ( struct V_81 * V_82 , T_1 V_3 )
{
V_82 -> V_83 |= V_3 & ~ V_82 -> V_49 ;
}
static inline void F_24 ( struct V_81 * V_82 , T_1 V_3 )
{
V_82 -> V_49 |= V_3 & ~ V_82 -> V_83 ;
}
static int F_25 ( struct V_73 * V_74 , struct V_78 * V_96 , T_2 V_95 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_96 -> V_91 ; V_70 ++ )
if ( V_96 -> V_53 [ V_70 ] . V_95 == V_95 )
return V_70 ;
V_96 -> V_91 ++ ;
V_96 -> V_53 [ V_70 ] . V_95 = V_95 ;
V_96 -> V_53 [ V_70 ] . V_94 . V_83 = V_74 -> V_97 . V_83 ;
V_96 -> V_53 [ V_70 ] . V_94 . V_49 = V_74 -> V_97 . V_49 ;
return V_70 ;
}
static void F_26 ( struct V_78 * V_96 , T_1 V_3 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_96 -> V_91 ; V_70 ++ )
F_24 ( & V_96 -> V_53 [ V_70 ] . V_94 , V_3 ) ;
}
static void F_27 ( struct V_78 * V_96 , T_1 V_3 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_96 -> V_91 ; V_70 ++ )
F_23 ( & V_96 -> V_53 [ V_70 ] . V_94 , V_3 ) ;
}
static void F_28 ( struct V_73 * V_74 ,
struct V_47 * V_48 )
{
T_1 V_3 = V_48 -> V_57 ;
int V_70 ;
V_74 -> V_77 = 0 ;
switch ( F_29 ( V_48 ) ) {
case V_34 :
if ( V_48 -> type == V_60 ) {
F_23 ( & V_74 -> V_35 , V_3 ) ;
} else {
F_24 ( & V_74 -> V_35 , V_3 ) ;
}
break;
case V_39 :
V_70 = F_25 ( V_74 , V_74 -> V_40 , V_48 -> V_62 ) ;
if ( V_48 -> type == V_60 ) {
F_23 ( & V_74 -> V_40 -> V_53 [ V_70 ] . V_94 , V_3 ) ;
} else {
F_24 ( & V_74 -> V_40 -> V_53 [ V_70 ] . V_94 , V_3 ) ;
V_3 = V_74 -> V_40 -> V_53 [ V_70 ] . V_94 . V_49 ;
F_24 ( & V_74 -> V_35 , V_3 ) ;
}
break;
case V_37 :
if ( V_48 -> type == V_60 ) {
F_23 ( & V_74 -> V_38 , V_3 ) ;
} else {
F_24 ( & V_74 -> V_38 , V_3 ) ;
V_3 = V_74 -> V_38 . V_49 ;
F_24 ( & V_74 -> V_35 , V_3 ) ;
F_24 ( & V_74 -> V_97 , V_3 ) ;
F_26 ( V_74 -> V_40 , V_3 ) ;
F_26 ( V_74 -> V_42 , V_3 ) ;
}
break;
case V_41 :
V_70 = F_25 ( V_74 , V_74 -> V_42 , V_48 -> V_62 ) ;
if ( V_48 -> type == V_60 ) {
F_23 ( & V_74 -> V_42 -> V_53 [ V_70 ] . V_94 , V_3 ) ;
} else {
F_24 ( & V_74 -> V_42 -> V_53 [ V_70 ] . V_94 , V_3 ) ;
V_3 = V_74 -> V_42 -> V_53 [ V_70 ] . V_94 . V_49 ;
F_24 ( & V_74 -> V_35 , V_3 ) ;
F_24 ( & V_74 -> V_38 , V_3 ) ;
F_24 ( & V_74 -> V_97 , V_3 ) ;
F_26 ( V_74 -> V_40 , V_3 ) ;
F_26 ( V_74 -> V_42 , V_3 ) ;
}
break;
case V_43 :
if ( V_48 -> type == V_60 ) {
F_23 ( & V_74 -> V_35 , V_3 ) ;
F_23 ( & V_74 -> V_38 , V_3 ) ;
F_23 ( & V_74 -> V_44 , V_3 ) ;
F_23 ( & V_74 -> V_97 , V_3 ) ;
F_27 ( V_74 -> V_40 , V_3 ) ;
F_27 ( V_74 -> V_42 , V_3 ) ;
} else {
F_24 ( & V_74 -> V_35 , V_3 ) ;
F_24 ( & V_74 -> V_38 , V_3 ) ;
F_24 ( & V_74 -> V_44 , V_3 ) ;
F_24 ( & V_74 -> V_97 , V_3 ) ;
F_26 ( V_74 -> V_40 , V_3 ) ;
F_26 ( V_74 -> V_42 , V_3 ) ;
}
}
}
int F_30 ( struct V_17 * V_21 , struct V_18 * * V_19 ,
struct V_18 * * V_20 , unsigned int V_2 )
{
struct V_73 V_98 , V_99 ;
struct V_47 * V_48 ;
int V_100 ;
V_100 = F_14 ( & V_98 , V_21 -> V_54 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_14 ( & V_99 , V_21 -> V_54 ) ;
if ( V_100 )
goto V_101;
V_100 = - V_23 ;
for ( V_48 = V_21 -> V_53 ; V_48 < V_21 -> V_53 + V_21 -> V_54 ; V_48 ++ ) {
if ( V_48 -> type != V_60 &&
V_48 -> type != V_55 )
goto V_102;
if ( V_48 -> V_56 & ~ V_103 )
goto V_102;
if ( ( V_48 -> V_56 & V_51 ) == 0 ) {
F_28 ( & V_98 , V_48 ) ;
continue;
}
if ( ! ( V_2 & V_11 ) )
goto V_102;
F_28 ( & V_99 , V_48 ) ;
if ( ! ( V_48 -> V_56 & V_52 ) )
F_28 ( & V_98 , V_48 ) ;
}
* V_19 = F_20 ( & V_98 , V_2 ) ;
if ( F_31 ( * V_19 ) ) {
V_100 = F_32 ( * V_19 ) ;
* V_19 = NULL ;
goto V_102;
}
* V_20 = F_20 ( & V_99 ,
V_2 | V_26 ) ;
if ( F_31 ( * V_20 ) ) {
V_100 = F_32 ( * V_20 ) ;
* V_20 = NULL ;
F_22 ( * V_19 ) ;
* V_19 = NULL ;
goto V_102;
}
F_13 ( * V_19 ) ;
F_13 ( * V_20 ) ;
V_100 = 0 ;
V_102:
F_17 ( & V_99 ) ;
V_101:
F_17 ( & V_98 ) ;
return V_100 ;
}
static short
F_29 ( struct V_47 * V_48 )
{
switch ( V_48 -> V_58 ) {
case V_61 :
return ( V_48 -> V_56 & V_65 ?
V_41 : V_39 ) ;
case V_59 :
return V_34 ;
case V_64 :
return V_37 ;
case V_66 :
return V_43 ;
}
F_33 () ;
return - 1 ;
}
struct V_17 *
F_7 ( int V_91 )
{
struct V_17 * V_21 ;
V_21 = F_34 ( sizeof( * V_21 ) + V_91 * sizeof( struct V_47 ) , V_80 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_54 = 0 ;
return V_21 ;
}
int
F_35 ( char * V_104 , T_1 V_105 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_36 ( V_106 ) ; V_70 ++ ) {
if ( V_106 [ V_70 ] . V_107 == V_105 &&
0 == memcmp ( V_106 [ V_70 ] . string , V_104 , V_105 ) )
return V_106 [ V_70 ] . type ;
}
return V_61 ;
}
int
F_37 ( int V_62 , char * V_104 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_36 ( V_106 ) ; V_70 ++ ) {
if ( V_106 [ V_70 ] . type == V_62 ) {
memcpy ( V_104 , V_106 [ V_70 ] . string , V_106 [ V_70 ] . V_107 ) ;
return V_106 [ V_70 ] . V_107 ;
}
}
F_33 () ;
return - 1 ;
}
