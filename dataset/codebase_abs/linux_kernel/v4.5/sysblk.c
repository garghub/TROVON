static inline int F_1 ( int V_1 , int V_2 )
{
return ( V_1 * V_3 ) + V_2 ;
}
void F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
V_5 -> V_8 = F_3 ( V_7 -> V_8 ) ;
V_5 -> V_9 = F_3 ( V_7 -> V_9 ) ;
V_5 -> V_10 = F_4 ( V_7 -> V_10 ) ;
strncpy ( V_5 -> V_11 , V_7 -> V_11 , V_12 ) ;
V_5 -> V_13 . V_14 = F_5 ( V_7 -> V_13 ) ;
}
void F_6 ( struct V_6 * V_7 , struct V_4 * V_5 )
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
int V_21 = F_11 ( int , V_22 , V_18 -> V_23 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ )
V_20 [ V_24 ] . V_14 = 0 ;
switch ( V_18 -> V_23 ) {
case 2 :
V_20 [ 1 ] . V_25 . V_26 = 1 ;
case 1 :
V_20 [ 0 ] . V_25 . V_26 = 0 ;
break;
default:
V_20 [ 0 ] . V_25 . V_26 = 0 ;
V_20 [ 1 ] . V_25 . V_26 = V_18 -> V_23 / 2 ;
V_20 [ 2 ] . V_25 . V_26 = V_18 -> V_23 - 1 ;
break;
}
return V_21 ;
}
void F_12 ( struct V_17 * V_18 , struct V_27 * V_28 ,
struct V_19 * V_20 )
{
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 -> V_21 = F_10 ( V_18 , V_20 ) ;
}
static int F_13 ( struct V_19 V_14 , int V_29 , T_1 * V_30 ,
void * V_31 )
{
struct V_27 * V_28 = V_31 ;
int V_24 , V_32 = 0 ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
if ( V_30 [ V_24 ] != V_33 )
continue;
if ( V_28 -> V_34 == V_3 * V_22 ) {
F_14 ( L_1 ) ;
return - V_35 ;
}
V_14 . V_25 . V_36 = V_24 ;
V_28 -> V_37 [ F_1 ( V_28 -> V_1 , V_32 ) ] = V_14 ;
V_28 -> V_34 ++ ;
V_32 ++ ;
}
return 0 ;
}
static int F_15 ( struct V_17 * V_18 , struct V_27 * V_28 ,
struct V_19 * V_37 , T_2 * V_38 )
{
struct V_19 V_39 ;
int V_24 , V_40 ;
V_28 -> V_34 = 0 ;
for ( V_24 = 0 ; V_24 < V_28 -> V_21 ; V_24 ++ ) {
V_39 = F_16 ( V_18 , V_37 [ V_24 ] ) ;
V_28 -> V_1 = V_24 ;
V_40 = V_18 -> V_41 -> V_42 ( V_18 , V_39 , V_18 -> V_43 , V_38 , V_28 ) ;
if ( V_40 ) {
F_14 ( L_2 ,
V_37 [ V_24 ] . V_25 . V_26 ,
V_37 [ V_24 ] . V_25 . V_36 ) ;
return V_40 ;
}
}
return V_40 ;
}
static int F_17 ( struct V_17 * V_18 , struct V_19 * V_14 ,
struct V_6 * V_44 )
{
struct V_6 * V_45 ;
int V_46 , V_47 , V_40 , V_48 = 0 ;
V_47 = V_18 -> V_49 * V_18 -> V_50 * V_18 -> V_51 ;
V_45 = F_18 ( V_47 , V_52 ) ;
if ( ! V_45 )
return - V_53 ;
for ( V_46 = 0 ; V_46 < V_18 -> V_54 ; V_46 ++ ) {
V_14 -> V_25 . V_46 = F_19 ( V_18 , V_46 ) ;
V_40 = F_20 ( V_18 , V_14 , 1 , V_55 , V_56 ,
V_45 , V_47 ) ;
if ( V_40 ) {
if ( V_40 == V_57 ) {
F_21 ( L_3 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_58 ,
V_14 -> V_25 . V_36 ,
V_14 -> V_25 . V_46 ) ;
break;
}
F_14 ( L_4 ,
V_40 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_58 ,
V_14 -> V_25 . V_36 ,
V_14 -> V_25 . V_46 ) ;
break;
}
if ( F_3 ( V_45 -> V_15 ) != V_16 ) {
F_21 ( L_5 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_58 ,
V_14 -> V_25 . V_36 ,
V_14 -> V_25 . V_46 ) ;
break;
}
if ( F_3 ( V_45 -> V_8 ) < F_3 ( V_44 -> V_8 ) )
continue;
memcpy ( V_44 , V_45 , sizeof( struct V_6 ) ) ;
V_48 = 1 ;
}
F_22 ( V_45 ) ;
return V_48 ;
}
static int F_23 ( struct V_17 * V_18 , struct V_27 * V_28 , int type )
{
struct V_59 V_60 ;
int V_40 ;
if ( V_28 -> V_34 > V_18 -> V_41 -> V_61 ) {
F_14 ( L_6 ) ;
return - V_35 ;
}
memset ( & V_60 , 0 , sizeof( struct V_59 ) ) ;
F_24 ( V_18 , & V_60 , V_28 -> V_37 , V_28 -> V_34 ) ;
F_25 ( V_18 , & V_60 ) ;
V_40 = V_18 -> V_41 -> V_62 ( V_18 , & V_60 , type ) ;
F_26 ( V_18 , & V_60 ) ;
if ( V_40 ) {
F_14 ( L_7 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_27 ( struct V_19 V_14 , int V_29 , T_1 * V_30 ,
void * V_31 )
{
struct V_27 * V_28 = V_31 ;
struct V_19 * V_63 ;
int V_24 , V_2 = 0 ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
if ( V_30 [ V_24 ] == V_33 )
return - V_64 ;
if ( V_30 [ V_24 ] != V_65 )
continue;
V_63 = & V_28 -> V_37 [ F_1 ( V_28 -> V_1 , V_2 ) ] ;
V_63 -> V_25 . V_26 = V_14 . V_25 . V_26 ;
V_63 -> V_25 . V_58 = V_14 . V_25 . V_58 ;
V_63 -> V_25 . V_36 = V_24 ;
V_28 -> V_34 ++ ;
V_2 ++ ;
F_21 ( L_8 ,
V_63 -> V_25 . V_26 , V_63 -> V_25 . V_58 , V_63 -> V_25 . V_36 ) ;
if ( V_2 > V_3 - 1 )
return 0 ;
}
F_14 ( L_9 ) ;
return - V_35 ;
}
static int F_28 ( struct V_17 * V_18 , struct V_4 * V_5 ,
struct V_27 * V_28 )
{
struct V_6 V_66 ;
void * V_67 ;
int V_24 , V_68 , V_40 , V_69 ;
struct V_19 * V_37 ;
F_6 ( & V_66 , V_5 ) ;
V_69 = V_18 -> V_49 * V_18 -> V_50 * V_18 -> V_51 ;
V_67 = F_29 ( V_69 , V_52 ) ;
if ( ! V_67 )
return - V_53 ;
memcpy ( V_67 , & V_66 , sizeof( struct V_6 ) ) ;
V_37 = F_30 ( V_18 -> V_50 , sizeof( struct V_19 ) , V_52 ) ;
if ( ! V_37 ) {
V_40 = - V_53 ;
goto V_70;
}
for ( V_24 = 0 ; V_24 < V_28 -> V_21 ; V_24 ++ ) {
V_37 [ 0 ] = V_28 -> V_37 [ F_1 ( V_24 , V_28 -> V_71 [ V_24 ] ) ] ;
F_21 ( L_10 ,
V_37 [ 0 ] . V_25 . V_26 ,
V_37 [ 0 ] . V_25 . V_58 ,
V_37 [ 0 ] . V_25 . V_36 ,
V_37 [ 0 ] . V_25 . V_46 ) ;
if ( V_18 -> V_50 > 1 ) {
for ( V_68 = 1 ; V_68 < V_18 -> V_50 ; V_68 ++ ) {
V_37 [ V_68 ] . V_14 = V_37 [ 0 ] . V_14 ;
V_37 [ V_68 ] . V_25 . V_72 = V_68 ;
}
}
V_40 = F_20 ( V_18 , V_37 , V_18 -> V_50 , V_73 ,
V_56 , V_67 , V_69 ) ;
if ( V_40 ) {
F_14 ( L_11 ,
V_37 [ 0 ] . V_25 . V_26 ,
V_37 [ 0 ] . V_25 . V_58 ,
V_37 [ 0 ] . V_25 . V_36 ) ;
break;
}
V_40 = F_20 ( V_18 , V_37 , V_18 -> V_50 , V_55 ,
V_56 , V_67 , V_69 ) ;
if ( V_40 ) {
F_14 ( L_12 ,
V_37 [ 0 ] . V_25 . V_26 ,
V_37 [ 0 ] . V_25 . V_58 ,
V_37 [ 0 ] . V_25 . V_36 ) ;
break;
}
if ( memcmp ( V_67 , & V_66 , sizeof( struct V_6 ) ) ) {
F_14 ( L_13 ,
V_37 [ 0 ] . V_25 . V_26 ,
V_37 [ 0 ] . V_25 . V_58 ,
V_37 [ 0 ] . V_25 . V_36 ) ;
V_40 = - V_35 ;
break;
}
}
F_22 ( V_37 ) ;
V_70:
F_22 ( V_67 ) ;
return V_40 ;
}
static int F_31 ( struct V_17 * V_18 , struct V_27 * V_28 )
{
int V_24 , V_40 ;
unsigned long V_74 ;
struct V_19 * V_14 ;
for ( V_24 = 0 ; V_24 < V_28 -> V_21 ; V_24 ++ ) {
V_74 = ( V_28 -> V_71 [ V_24 ] + 1 ) % V_3 ;
V_14 = & V_28 -> V_37 [ F_1 ( V_24 , V_74 ) ] ;
V_14 -> V_25 . V_46 = F_19 ( V_18 , 0 ) ;
V_40 = F_32 ( V_18 , V_14 , 1 ) ;
if ( V_40 )
return V_40 ;
V_28 -> V_71 [ V_24 ] = V_74 ;
}
return 0 ;
}
int F_33 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
struct V_6 * V_45 ;
int V_24 , V_75 , V_48 = 0 ;
int V_40 = - V_53 ;
if ( ! V_18 -> V_41 -> V_42 )
return - V_35 ;
F_12 ( V_18 , & V_28 , V_20 ) ;
F_34 ( & V_18 -> V_76 ) ;
V_40 = F_15 ( V_18 , & V_28 , V_20 , F_13 ) ;
if ( V_40 )
goto V_77;
if ( ! V_28 . V_34 )
goto V_77;
V_45 = F_29 ( sizeof( struct V_6 ) , V_52 ) ;
if ( ! V_45 )
goto V_77;
for ( V_24 = 0 ; V_24 < V_28 . V_21 ; V_24 ++ ) {
for ( V_75 = 0 ; V_75 < V_3 ; V_75 ++ ) {
struct V_19 V_14 = V_28 . V_37 [ F_1 ( V_24 , V_75 ) ] ;
V_40 = F_17 ( V_18 , & V_14 , V_45 ) ;
if ( V_40 > 0 )
V_48 = 1 ;
else if ( V_40 < 0 )
break;
}
}
F_2 ( V_5 , V_45 ) ;
F_22 ( V_45 ) ;
V_77:
F_35 ( & V_18 -> V_76 ) ;
if ( V_48 )
return 1 ;
return V_40 ;
}
int F_36 ( struct V_17 * V_18 , struct V_4 * V_78 )
{
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
struct V_6 * V_45 ;
int V_24 , V_75 , V_79 , V_48 = 0 ;
int V_40 = - V_53 ;
if ( ! V_18 -> V_41 -> V_42 )
return - V_35 ;
F_12 ( V_18 , & V_28 , V_20 ) ;
F_34 ( & V_18 -> V_76 ) ;
V_40 = F_15 ( V_18 , & V_28 , V_20 , F_13 ) ;
if ( V_40 )
goto V_77;
V_45 = F_29 ( sizeof( struct V_6 ) , V_52 ) ;
if ( ! V_45 )
goto V_77;
for ( V_24 = 0 ; V_24 < V_28 . V_21 ; V_24 ++ ) {
V_48 = 0 ;
for ( V_75 = 0 ; V_75 < V_3 ; V_75 ++ ) {
V_79 = F_1 ( V_24 , V_75 ) ;
V_40 = F_17 ( V_18 , & V_28 . V_37 [ V_79 ] , V_45 ) ;
if ( V_40 > 0 ) {
V_28 . V_71 [ V_24 ] = V_75 ;
V_48 = 1 ;
} else if ( V_40 < 0 )
break;
}
}
if ( ! V_48 ) {
F_14 ( L_14 ) ;
V_40 = - V_35 ;
goto V_80;
}
for ( V_24 = 1 ; V_24 < V_28 . V_21 ; V_24 ++ ) {
struct V_19 V_81 = V_28 . V_37 [ F_1 ( 0 , V_28 . V_71 [ 0 ] ) ] ;
struct V_19 V_82 = V_28 . V_37 [ F_1 ( V_24 , V_28 . V_71 [ V_24 ] ) ] ;
if ( V_81 . V_25 . V_46 != V_82 . V_25 . V_46 ) {
F_14 ( L_15 ) ;
V_40 = - V_35 ;
goto V_80;
}
}
if ( ( V_78 -> V_8 - 1 ) != F_3 ( V_45 -> V_8 ) ) {
F_14 ( L_16 ) ;
V_40 = - V_35 ;
goto V_80;
}
if ( V_28 . V_37 [ F_1 ( 0 , V_28 . V_71 [ 0 ] ) ] . V_25 . V_46 ==
V_18 -> V_54 - 1 ) {
V_40 = F_31 ( V_18 , & V_28 ) ;
if ( V_40 )
goto V_80;
}
V_40 = F_28 ( V_18 , V_78 , & V_28 ) ;
V_80:
F_22 ( V_45 ) ;
V_77:
F_35 ( & V_18 -> V_76 ) ;
return V_40 ;
}
int F_37 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
int V_40 ;
if ( ! V_18 -> V_41 -> V_42 || ! V_18 -> V_41 -> V_62 )
return - V_35 ;
if ( ! ( V_18 -> V_83 & V_84 ) || ! V_18 -> V_54 ) {
F_14 ( L_17 ) ;
return - V_35 ;
}
F_12 ( V_18 , & V_28 , V_20 ) ;
F_34 ( & V_18 -> V_76 ) ;
V_40 = F_15 ( V_18 , & V_28 , V_20 , F_27 ) ;
if ( V_40 )
goto V_85;
V_40 = F_23 ( V_18 , & V_28 , V_33 ) ;
if ( V_40 )
goto V_85;
V_40 = F_28 ( V_18 , V_5 , & V_28 ) ;
V_85:
F_35 ( & V_18 -> V_76 ) ;
return V_40 ;
}
static int F_38 ( int V_86 )
{
return ( V_86 + ( V_87 - 1 ) ) & ~ ( V_87 - 1 ) ;
}
static unsigned int F_39 ( struct V_17 * V_18 , int V_26 , int V_58 )
{
int V_86 = F_38 ( V_18 -> V_43 ) ;
return ( ( V_26 * V_18 -> V_88 * V_86 ) + ( V_58 * V_86 ) ) /
V_87 ;
}
static int F_40 ( struct V_19 V_14 , int V_29 , T_1 * V_30 ,
void * V_31 )
{
struct V_89 * V_90 = V_31 ;
struct V_17 * V_18 = V_90 -> V_18 ;
int V_24 , V_91 ;
V_91 = F_39 ( V_18 , V_14 . V_25 . V_26 , V_14 . V_25 . V_58 ) ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
switch ( V_30 [ V_24 ] ) {
case V_65 :
if ( V_90 -> V_92 & V_93 )
F_41 ( V_24 , & V_90 -> V_30 [ V_91 ] ) ;
break;
case V_33 :
if ( ! ( V_90 -> V_92 & V_94 ) )
F_41 ( V_24 , & V_90 -> V_30 [ V_91 ] ) ;
break;
case V_95 :
if ( ! ( V_90 -> V_92 & V_96 ) )
F_41 ( V_24 , & V_90 -> V_30 [ V_91 ] ) ;
break;
default:
F_41 ( V_24 , & V_90 -> V_30 [ V_91 ] ) ;
break;
}
}
return 0 ;
}
static int F_42 ( struct V_17 * V_18 , struct V_19 * V_97 ,
int V_98 , struct V_89 * V_90 )
{
struct V_19 V_14 ;
int V_26 , V_58 , V_2 , V_99 , V_100 = 0 , V_101 = 0 ;
unsigned long * V_102 ;
while ( ! V_100 ) {
V_100 = 1 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_23 ; V_26 ++ ) {
for ( V_58 = 0 ; V_58 < V_18 -> V_88 ; V_58 ++ ) {
V_99 = F_39 ( V_18 , V_26 , V_58 ) ;
V_102 = & V_90 -> V_30 [ V_99 ] ;
V_2 = F_43 ( V_102 ,
V_18 -> V_43 ) ;
if ( V_2 >= V_18 -> V_43 )
continue;
F_41 ( V_2 , V_102 ) ;
V_14 . V_14 = 0 ;
V_14 . V_25 . V_26 = V_26 ;
V_14 . V_25 . V_58 = V_58 ;
V_14 . V_25 . V_36 = V_2 ;
F_21 ( L_18 ,
V_14 . V_25 . V_26 ,
V_14 . V_25 . V_58 ,
V_14 . V_25 . V_36 ) ;
V_97 [ V_101 ] = V_14 ;
V_101 ++ ;
V_100 = 0 ;
if ( V_101 == V_98 )
return V_101 ;
}
}
}
return V_101 ;
}
static int F_44 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_2 * V_38 , void * V_103 )
{
struct V_19 V_104 ;
int V_40 ;
V_104 = F_16 ( V_18 , V_14 ) ;
V_40 = V_18 -> V_41 -> V_42 ( V_18 , V_104 , V_18 -> V_43 , V_38 , V_103 ) ;
if ( V_40 )
F_14 ( L_19 ,
V_14 . V_25 . V_26 , V_14 . V_25 . V_36 ) ;
return V_40 ;
}
static int F_45 ( struct V_17 * V_18 , struct V_89 * V_90 )
{
int V_26 , V_58 , V_40 ;
struct V_19 V_14 ;
V_14 . V_14 = 0 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_23 ; V_26 ++ ) {
for ( V_58 = 0 ; V_58 < V_18 -> V_88 ; V_58 ++ ) {
V_14 . V_25 . V_26 = V_26 ;
V_14 . V_25 . V_58 = V_58 ;
V_40 = F_44 ( V_18 , V_14 , F_40 ,
V_90 ) ;
if ( V_40 )
return V_40 ;
}
}
return 0 ;
}
int F_46 ( struct V_17 * V_18 , int V_92 )
{
struct V_89 V_90 ;
struct V_19 * V_37 ;
int V_101 , V_40 = - V_53 ;
int V_98 = V_18 -> V_41 -> V_61 / V_18 -> V_51 ;
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
V_90 . V_30 = F_29 ( F_38 ( V_18 -> V_43 ) * V_18 -> V_105 ,
V_52 ) ;
if ( ! V_90 . V_30 )
return V_40 ;
V_37 = F_30 ( V_98 , sizeof( struct V_19 ) , V_52 ) ;
if ( ! V_37 )
goto V_106;
V_90 . V_18 = V_18 ;
V_90 . V_92 = V_92 ;
V_40 = F_45 ( V_18 , & V_90 ) ;
if ( V_40 )
goto V_107;
while ( ( V_101 = F_42 ( V_18 , V_37 , V_98 , & V_90 ) ) > 0 )
F_32 ( V_18 , V_37 , V_101 ) ;
if ( V_92 & V_94 ) {
F_12 ( V_18 , & V_28 , V_20 ) ;
F_34 ( & V_18 -> V_76 ) ;
V_40 = F_15 ( V_18 , & V_28 , V_20 ,
F_13 ) ;
if ( ! V_40 )
V_40 = F_23 ( V_18 , & V_28 , V_65 ) ;
F_35 ( & V_18 -> V_76 ) ;
}
V_107:
F_22 ( V_37 ) ;
V_106:
F_22 ( V_90 . V_30 ) ;
return V_40 ;
}
