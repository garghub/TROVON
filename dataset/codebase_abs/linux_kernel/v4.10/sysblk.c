static inline int F_1 ( int V_1 , int V_2 )
{
return ( V_1 * V_3 ) + V_2 ;
}
static void F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
V_5 -> V_8 = F_3 ( V_7 -> V_8 ) ;
V_5 -> V_9 = F_3 ( V_7 -> V_9 ) ;
V_5 -> V_10 = F_4 ( V_7 -> V_10 ) ;
strncpy ( V_5 -> V_11 , V_7 -> V_11 , V_12 ) ;
V_5 -> V_13 . V_14 = F_5 ( V_7 -> V_13 ) ;
}
static void F_6 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
V_7 -> V_15 = F_7 ( V_16 ) ;
V_7 -> V_8 = F_7 ( V_5 -> V_8 ) ;
V_7 -> V_9 = F_7 ( V_5 -> V_9 ) ;
V_7 -> V_10 = F_8 ( V_5 -> V_10 ) ;
strncpy ( V_7 -> V_11 , V_5 -> V_11 , V_12 ) ;
V_7 -> V_13 = F_9 ( V_5 -> V_13 . V_14 ) ;
}
static int F_10 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
int V_23 = F_11 ( int , V_24 , V_22 -> V_25 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_23 ; V_26 ++ )
V_20 [ V_26 ] . V_14 = 0 ;
switch ( V_22 -> V_25 ) {
case 2 :
V_20 [ 1 ] . V_27 . V_28 = 1 ;
case 1 :
V_20 [ 0 ] . V_27 . V_28 = 0 ;
break;
default:
V_20 [ 0 ] . V_27 . V_28 = 0 ;
V_20 [ 1 ] . V_27 . V_28 = V_22 -> V_25 / 2 ;
V_20 [ 2 ] . V_27 . V_28 = V_22 -> V_25 - 1 ;
break;
}
return V_23 ;
}
static void F_12 ( struct V_17 * V_18 , struct V_29 * V_30 ,
struct V_19 * V_20 )
{
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_23 = F_10 ( V_18 , V_20 ) ;
}
static int F_13 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_1 * V_31 , int V_32 ,
struct V_29 * V_30 )
{
struct V_19 * V_33 ;
int V_26 , V_2 = 0 ;
V_32 = F_14 ( V_18 , V_31 , V_32 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
if ( V_31 [ V_26 ] == V_34 )
return - V_35 ;
if ( V_31 [ V_26 ] != V_36 )
continue;
V_33 = & V_30 -> V_37 [ F_1 ( V_30 -> V_1 , V_2 ) ] ;
V_33 -> V_27 . V_28 = V_14 . V_27 . V_28 ;
V_33 -> V_27 . V_38 = V_14 . V_27 . V_38 ;
V_33 -> V_27 . V_39 = V_26 ;
V_30 -> V_40 ++ ;
V_2 ++ ;
F_15 ( L_1 ,
V_33 -> V_27 . V_28 , V_33 -> V_27 . V_38 , V_33 -> V_27 . V_39 ) ;
if ( V_2 > V_3 - 1 )
return 0 ;
}
F_16 ( L_2 ) ;
return - V_41 ;
}
static int F_17 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_1 * V_31 , int V_32 ,
struct V_29 * V_30 )
{
int V_26 , V_42 = 0 ;
V_32 = F_14 ( V_18 , V_31 , V_32 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
if ( V_31 [ V_26 ] != V_34 )
continue;
if ( V_30 -> V_40 == V_3 * V_24 ) {
F_16 ( L_3 ) ;
return - V_41 ;
}
V_14 . V_27 . V_39 = V_26 ;
V_30 -> V_37 [ F_1 ( V_30 -> V_1 , V_42 ) ] = V_14 ;
V_30 -> V_40 ++ ;
V_42 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_29 * V_30 ,
struct V_19 * V_37 , int V_43 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
int V_26 , V_32 , V_44 = 0 ;
T_1 * V_31 ;
V_30 -> V_40 = 0 ;
V_32 = V_22 -> V_45 * V_22 -> V_46 ;
V_31 = F_19 ( V_32 , V_47 ) ;
if ( ! V_31 )
return - V_48 ;
for ( V_26 = 0 ; V_26 < V_30 -> V_23 ; V_26 ++ ) {
V_30 -> V_1 = V_26 ;
V_44 = F_20 ( V_18 , V_37 [ V_26 ] , V_31 ) ;
if ( V_44 ) {
F_16 ( L_4 ,
V_37 [ V_26 ] . V_27 . V_28 ,
V_37 [ V_26 ] . V_27 . V_39 ) ;
goto V_49;
}
if ( V_43 )
V_44 = F_13 ( V_18 , V_37 [ V_26 ] , V_31 , V_32 ,
V_30 ) ;
else
V_44 = F_17 ( V_18 , V_37 [ V_26 ] , V_31 , V_32 ,
V_30 ) ;
if ( V_44 )
goto V_49;
}
V_49:
F_21 ( V_31 ) ;
return V_44 ;
}
static int F_22 ( struct V_17 * V_18 , struct V_19 * V_14 ,
struct V_6 * V_50 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_6 * V_51 ;
int V_52 , V_44 , V_53 = 0 ;
V_51 = F_19 ( V_22 -> V_54 , V_47 ) ;
if ( ! V_51 )
return - V_48 ;
for ( V_52 = 0 ; V_52 < V_18 -> V_55 ; V_52 ++ ) {
V_14 -> V_27 . V_52 = F_23 ( V_18 , V_52 ) ;
V_44 = F_24 ( V_18 , V_14 , 1 , V_56 , V_57 ,
V_51 , V_22 -> V_54 ) ;
if ( V_44 ) {
if ( V_44 == V_58 ) {
F_15 ( L_5 ,
V_14 -> V_27 . V_28 ,
V_14 -> V_27 . V_38 ,
V_14 -> V_27 . V_39 ,
V_14 -> V_27 . V_52 ) ;
break;
}
F_16 ( L_6 ,
V_44 ,
V_14 -> V_27 . V_28 ,
V_14 -> V_27 . V_38 ,
V_14 -> V_27 . V_39 ,
V_14 -> V_27 . V_52 ) ;
break;
}
if ( F_3 ( V_51 -> V_15 ) != V_16 ) {
F_15 ( L_7 ,
V_14 -> V_27 . V_28 ,
V_14 -> V_27 . V_38 ,
V_14 -> V_27 . V_39 ,
V_14 -> V_27 . V_52 ) ;
break;
}
if ( F_3 ( V_51 -> V_8 ) < F_3 ( V_50 -> V_8 ) )
continue;
memcpy ( V_50 , V_51 , sizeof( struct V_6 ) ) ;
V_53 = 1 ;
}
F_21 ( V_51 ) ;
return V_53 ;
}
static int F_25 ( struct V_17 * V_18 , struct V_29 * V_30 ,
int type )
{
return F_26 ( V_18 , V_30 -> V_37 , V_30 -> V_40 , type ) ;
}
static int F_27 ( struct V_17 * V_18 , struct V_4 * V_5 ,
struct V_29 * V_30 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_6 V_59 ;
void * V_60 ;
int V_26 , V_61 , V_44 = 0 ;
struct V_19 * V_37 ;
F_6 ( & V_59 , V_5 ) ;
V_60 = F_28 ( V_22 -> V_54 , V_47 ) ;
if ( ! V_60 )
return - V_48 ;
memcpy ( V_60 , & V_59 , sizeof( struct V_6 ) ) ;
V_37 = F_29 ( V_22 -> V_62 , sizeof( struct V_19 ) , V_47 ) ;
if ( ! V_37 ) {
V_44 = - V_48 ;
goto V_63;
}
for ( V_26 = 0 ; V_26 < V_30 -> V_23 ; V_26 ++ ) {
V_37 [ 0 ] = V_30 -> V_37 [ F_1 ( V_26 , V_30 -> V_64 [ V_26 ] ) ] ;
F_15 ( L_8 ,
V_37 [ 0 ] . V_27 . V_28 ,
V_37 [ 0 ] . V_27 . V_38 ,
V_37 [ 0 ] . V_27 . V_39 ,
V_37 [ 0 ] . V_27 . V_52 ) ;
if ( V_22 -> V_62 > 1 ) {
for ( V_61 = 1 ; V_61 < V_22 -> V_62 ; V_61 ++ ) {
V_37 [ V_61 ] . V_14 = V_37 [ 0 ] . V_14 ;
V_37 [ V_61 ] . V_27 . V_65 = V_61 ;
}
}
V_44 = F_24 ( V_18 , V_37 , V_22 -> V_62 , V_66 ,
V_57 , V_60 , V_22 -> V_54 ) ;
if ( V_44 ) {
F_16 ( L_9 ,
V_37 [ 0 ] . V_27 . V_28 ,
V_37 [ 0 ] . V_27 . V_38 ,
V_37 [ 0 ] . V_27 . V_39 ) ;
break;
}
V_44 = F_24 ( V_18 , V_37 , V_22 -> V_62 , V_56 ,
V_57 , V_60 , V_22 -> V_54 ) ;
if ( V_44 ) {
F_16 ( L_10 ,
V_37 [ 0 ] . V_27 . V_28 ,
V_37 [ 0 ] . V_27 . V_38 ,
V_37 [ 0 ] . V_27 . V_39 ) ;
break;
}
if ( memcmp ( V_60 , & V_59 , sizeof( struct V_6 ) ) ) {
F_16 ( L_11 ,
V_37 [ 0 ] . V_27 . V_28 ,
V_37 [ 0 ] . V_27 . V_38 ,
V_37 [ 0 ] . V_27 . V_39 ) ;
V_44 = - V_41 ;
break;
}
}
F_21 ( V_37 ) ;
V_63:
F_21 ( V_60 ) ;
return V_44 ;
}
static int F_30 ( struct V_17 * V_18 , struct V_29 * V_30 )
{
int V_26 , V_44 ;
unsigned long V_67 ;
struct V_19 * V_14 ;
for ( V_26 = 0 ; V_26 < V_30 -> V_23 ; V_26 ++ ) {
V_67 = ( V_30 -> V_64 [ V_26 ] + 1 ) % V_3 ;
V_14 = & V_30 -> V_37 [ F_1 ( V_26 , V_67 ) ] ;
V_14 -> V_27 . V_52 = F_23 ( V_18 , 0 ) ;
V_44 = F_31 ( V_18 , V_14 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_30 -> V_64 [ V_26 ] = V_67 ;
}
return 0 ;
}
int F_32 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_19 V_20 [ V_24 ] ;
struct V_29 V_30 ;
struct V_6 * V_51 ;
int V_26 , V_68 , V_53 = 0 ;
int V_44 = - V_48 ;
if ( ! V_18 -> V_69 -> V_70 )
return - V_41 ;
F_12 ( V_18 , & V_30 , V_20 ) ;
F_33 ( & V_18 -> V_71 ) ;
V_44 = F_18 ( V_18 , & V_30 , V_20 , 0 ) ;
if ( V_44 )
goto V_72;
if ( ! V_30 . V_40 )
goto V_72;
V_51 = F_28 ( sizeof( struct V_6 ) , V_47 ) ;
if ( ! V_51 )
goto V_72;
for ( V_26 = 0 ; V_26 < V_30 . V_23 ; V_26 ++ ) {
for ( V_68 = 0 ; V_68 < V_3 ; V_68 ++ ) {
struct V_19 V_14 = V_30 . V_37 [ F_1 ( V_26 , V_68 ) ] ;
V_44 = F_22 ( V_18 , & V_14 , V_51 ) ;
if ( V_44 > 0 )
V_53 = 1 ;
else if ( V_44 < 0 )
break;
}
}
F_2 ( V_5 , V_51 ) ;
F_21 ( V_51 ) ;
V_72:
F_34 ( & V_18 -> V_71 ) ;
if ( V_53 )
return 1 ;
return V_44 ;
}
int F_35 ( struct V_17 * V_18 , struct V_4 * V_73 )
{
struct V_19 V_20 [ V_24 ] ;
struct V_29 V_30 ;
struct V_6 * V_51 ;
int V_26 , V_68 , V_74 , V_53 = 0 ;
int V_44 = - V_48 ;
if ( ! V_18 -> V_69 -> V_70 )
return - V_41 ;
F_12 ( V_18 , & V_30 , V_20 ) ;
F_33 ( & V_18 -> V_71 ) ;
V_44 = F_18 ( V_18 , & V_30 , V_20 , 0 ) ;
if ( V_44 )
goto V_72;
V_51 = F_28 ( sizeof( struct V_6 ) , V_47 ) ;
if ( ! V_51 )
goto V_72;
for ( V_26 = 0 ; V_26 < V_30 . V_23 ; V_26 ++ ) {
V_53 = 0 ;
for ( V_68 = 0 ; V_68 < V_3 ; V_68 ++ ) {
V_74 = F_1 ( V_26 , V_68 ) ;
V_44 = F_22 ( V_18 , & V_30 . V_37 [ V_74 ] , V_51 ) ;
if ( V_44 > 0 ) {
V_30 . V_64 [ V_26 ] = V_68 ;
V_53 = 1 ;
} else if ( V_44 < 0 )
break;
}
}
if ( ! V_53 ) {
F_16 ( L_12 ) ;
V_44 = - V_41 ;
goto V_75;
}
for ( V_26 = 1 ; V_26 < V_30 . V_23 ; V_26 ++ ) {
struct V_19 V_76 = V_30 . V_37 [ F_1 ( 0 , V_30 . V_64 [ 0 ] ) ] ;
struct V_19 V_77 = V_30 . V_37 [ F_1 ( V_26 , V_30 . V_64 [ V_26 ] ) ] ;
if ( V_76 . V_27 . V_52 != V_77 . V_27 . V_52 ) {
F_16 ( L_13 ) ;
V_44 = - V_41 ;
goto V_75;
}
}
if ( ( V_73 -> V_8 - 1 ) != F_3 ( V_51 -> V_8 ) ) {
F_16 ( L_14 ) ;
V_44 = - V_41 ;
goto V_75;
}
if ( V_30 . V_37 [ F_1 ( 0 , V_30 . V_64 [ 0 ] ) ] . V_27 . V_52 ==
V_18 -> V_55 - 1 ) {
V_44 = F_30 ( V_18 , & V_30 ) ;
if ( V_44 )
goto V_75;
}
V_44 = F_27 ( V_18 , V_73 , & V_30 ) ;
V_75:
F_21 ( V_51 ) ;
V_72:
F_34 ( & V_18 -> V_71 ) ;
return V_44 ;
}
int F_36 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_19 V_20 [ V_24 ] ;
struct V_29 V_30 ;
int V_44 ;
if ( ! V_18 -> V_69 -> V_70 || ! V_18 -> V_69 -> V_78 )
return - V_41 ;
if ( ! ( V_22 -> V_79 & V_80 ) || ! V_18 -> V_55 ) {
F_16 ( L_15 ) ;
return - V_41 ;
}
F_12 ( V_18 , & V_30 , V_20 ) ;
F_33 ( & V_18 -> V_71 ) ;
V_44 = F_18 ( V_18 , & V_30 , V_20 , 1 ) ;
if ( V_44 )
goto V_81;
V_44 = F_25 ( V_18 , & V_30 , V_34 ) ;
if ( V_44 )
goto V_81;
V_44 = F_27 ( V_18 , V_5 , & V_30 ) ;
V_81:
F_34 ( & V_18 -> V_71 ) ;
return V_44 ;
}
static int F_37 ( int V_82 )
{
return ( V_82 + ( V_83 - 1 ) ) & ~ ( V_83 - 1 ) ;
}
static unsigned int F_38 ( struct V_21 * V_22 , struct V_19 V_14 )
{
int V_82 = F_37 ( V_22 -> V_45 ) ;
return ( ( V_14 . V_27 . V_28 * V_22 -> V_84 * V_82 ) + ( V_14 . V_27 . V_38 * V_82 ) ) /
V_83 ;
}
static int F_39 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_1 * V_31 , int V_32 ,
unsigned long * V_85 , int V_86 )
{
int V_26 , V_87 ;
V_32 = F_14 ( V_18 , V_31 , V_32 ) ;
if ( V_32 < 0 )
return V_32 ;
V_87 = F_38 ( & V_18 -> V_22 , V_14 ) ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
switch ( V_31 [ V_26 ] ) {
case V_36 :
if ( V_86 & V_88 )
F_40 ( V_26 , & V_85 [ V_87 ] ) ;
break;
case V_34 :
if ( ! ( V_86 & V_89 ) )
F_40 ( V_26 , & V_85 [ V_87 ] ) ;
break;
case V_90 :
if ( ! ( V_86 & V_91 ) )
F_40 ( V_26 , & V_85 [ V_87 ] ) ;
break;
default:
F_40 ( V_26 , & V_85 [ V_87 ] ) ;
break;
}
}
return 0 ;
}
static int F_41 ( struct V_17 * V_18 , struct V_19 * V_92 ,
int V_93 , unsigned long * V_85 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_19 V_14 ;
int V_28 , V_38 , V_2 , V_94 , V_95 = 0 , V_96 = 0 ;
unsigned long * V_97 ;
while ( ! V_95 ) {
V_95 = 1 ;
F_42 (geo, ppa, ch, lun) {
V_94 = F_38 ( V_22 , V_14 ) ;
V_97 = & V_85 [ V_94 ] ;
V_2 = F_43 ( V_97 , V_22 -> V_45 ) ;
if ( V_2 >= V_22 -> V_45 )
continue;
F_40 ( V_2 , V_97 ) ;
V_14 . V_27 . V_39 = V_2 ;
F_15 ( L_16 ,
V_14 . V_27 . V_28 ,
V_14 . V_27 . V_38 ,
V_14 . V_27 . V_39 ) ;
V_92 [ V_96 ] = V_14 ;
V_96 ++ ;
V_95 = 0 ;
if ( V_96 == V_93 )
return V_96 ;
}
}
return V_96 ;
}
static int F_44 ( struct V_17 * V_18 , unsigned long * V_85 ,
int V_86 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_19 V_14 ;
int V_28 , V_38 , V_32 , V_44 = 0 ;
T_1 * V_31 ;
V_32 = V_22 -> V_45 * V_22 -> V_46 ;
V_31 = F_19 ( V_32 , V_47 ) ;
if ( ! V_31 )
return - V_48 ;
F_42 (geo, ppa, ch, lun) {
V_44 = F_20 ( V_18 , V_14 , V_31 ) ;
if ( V_44 )
F_16 ( L_17 ,
V_14 . V_27 . V_28 , V_14 . V_27 . V_39 ) ;
V_44 = F_39 ( V_18 , V_14 , V_31 , V_32 , V_85 ,
V_86 ) ;
if ( V_44 )
break;
}
F_21 ( V_31 ) ;
return V_44 ;
}
int F_45 ( struct V_17 * V_18 , int V_86 )
{
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_19 * V_37 ;
int V_96 , V_44 = - V_48 ;
int V_93 = V_18 -> V_69 -> V_98 / V_22 -> V_99 ;
struct V_19 V_20 [ V_24 ] ;
struct V_29 V_30 ;
unsigned long * V_85 ;
V_85 = F_28 ( F_37 ( V_22 -> V_45 ) * V_22 -> V_100 ,
V_47 ) ;
if ( ! V_85 )
return V_44 ;
V_37 = F_29 ( V_93 , sizeof( struct V_19 ) , V_47 ) ;
if ( ! V_37 )
goto V_101;
V_44 = F_44 ( V_18 , V_85 , V_86 ) ;
if ( V_44 )
goto V_102;
while ( ( V_96 =
F_41 ( V_18 , V_37 , V_93 , V_85 ) ) > 0 )
F_31 ( V_18 , V_37 , V_96 , 0 ) ;
if ( V_86 & V_89 ) {
F_12 ( V_18 , & V_30 , V_20 ) ;
F_33 ( & V_18 -> V_71 ) ;
V_44 = F_18 ( V_18 , & V_30 , V_20 , 0 ) ;
if ( ! V_44 )
V_44 = F_25 ( V_18 , & V_30 , V_36 ) ;
F_34 ( & V_18 -> V_71 ) ;
}
V_102:
F_21 ( V_37 ) ;
V_101:
F_21 ( V_85 ) ;
return V_44 ;
}
