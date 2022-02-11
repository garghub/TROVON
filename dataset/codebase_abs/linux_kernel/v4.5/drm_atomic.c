void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_2 ( V_2 -> V_8 ) ;
}
int
F_3 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
V_2 -> V_11 = true ;
V_2 -> V_5 = F_4 ( V_10 -> V_12 . V_13 ,
sizeof( * V_2 -> V_5 ) , V_14 ) ;
if ( ! V_2 -> V_5 )
goto V_15;
V_2 -> V_6 = F_4 ( V_10 -> V_12 . V_13 ,
sizeof( * V_2 -> V_6 ) , V_14 ) ;
if ( ! V_2 -> V_6 )
goto V_15;
V_2 -> V_7 = F_4 ( V_10 -> V_12 . V_16 ,
sizeof( * V_2 -> V_7 ) , V_14 ) ;
if ( ! V_2 -> V_7 )
goto V_15;
V_2 -> V_8 = F_4 ( V_10 -> V_12 . V_16 ,
sizeof( * V_2 -> V_8 ) , V_14 ) ;
if ( ! V_2 -> V_8 )
goto V_15;
V_2 -> V_10 = V_10 ;
F_5 ( L_1 , V_2 ) ;
return 0 ;
V_15:
F_1 ( V_2 ) ;
return - V_17 ;
}
struct V_1 *
F_6 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = & V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_19 -> V_20 -> V_21 ) {
V_2 = F_7 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return NULL ;
if ( F_3 ( V_10 , V_2 ) < 0 ) {
F_2 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
return V_19 -> V_20 -> V_21 ( V_10 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
int V_22 ;
F_5 ( L_2 , V_2 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 ; V_22 ++ ) {
struct V_24 * V_25 = V_2 -> V_3 [ V_22 ] ;
if ( ! V_25 )
continue;
V_2 -> V_4 [ V_22 ] -> V_25 = NULL ;
V_25 -> V_20 -> V_26 ( NULL ,
V_2 -> V_4 [ V_22 ] ) ;
V_2 -> V_3 [ V_22 ] = NULL ;
V_2 -> V_4 [ V_22 ] = NULL ;
}
for ( V_22 = 0 ; V_22 < V_19 -> V_13 ; V_22 ++ ) {
struct V_27 * V_28 = V_2 -> V_5 [ V_22 ] ;
if ( ! V_28 )
continue;
V_28 -> V_20 -> V_26 ( V_28 ,
V_2 -> V_6 [ V_22 ] ) ;
V_2 -> V_5 [ V_22 ] = NULL ;
V_2 -> V_6 [ V_22 ] = NULL ;
}
for ( V_22 = 0 ; V_22 < V_19 -> V_16 ; V_22 ++ ) {
struct V_29 * V_30 = V_2 -> V_7 [ V_22 ] ;
if ( ! V_30 )
continue;
V_30 -> V_20 -> V_26 ( V_30 ,
V_2 -> V_8 [ V_22 ] ) ;
V_2 -> V_7 [ V_22 ] = NULL ;
V_2 -> V_8 [ V_22 ] = NULL ;
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_19 -> V_20 -> V_31 )
V_19 -> V_20 -> V_31 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
V_19 = & V_10 -> V_12 ;
F_9 ( V_2 ) ;
F_5 ( L_3 , V_2 ) ;
if ( V_19 -> V_20 -> V_32 ) {
V_19 -> V_20 -> V_32 ( V_2 ) ;
} else {
F_1 ( V_2 ) ;
F_2 ( V_2 ) ;
}
}
struct V_33 *
F_11 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_34 , V_35 = F_12 ( V_28 ) ;
struct V_33 * V_36 ;
V_36 = F_13 ( V_2 , V_28 ) ;
if ( V_36 )
return V_36 ;
V_34 = F_14 ( & V_28 -> V_37 , V_2 -> V_38 ) ;
if ( V_34 )
return F_15 ( V_34 ) ;
V_36 = V_28 -> V_20 -> V_39 ( V_28 ) ;
if ( ! V_36 )
return F_15 ( - V_17 ) ;
V_2 -> V_6 [ V_35 ] = V_36 ;
V_2 -> V_5 [ V_35 ] = V_28 ;
V_36 -> V_2 = V_2 ;
F_5 ( L_4 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 , V_36 , V_2 ) ;
return V_36 ;
}
int F_16 ( struct V_33 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 V_46 ;
if ( V_44 && memcmp ( & V_2 -> V_44 , V_44 , sizeof( * V_44 ) ) == 0 )
return 0 ;
F_17 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_44 ) {
F_18 ( & V_46 , V_44 ) ;
V_2 -> V_47 =
F_19 ( V_2 -> V_28 -> V_10 ,
sizeof( V_46 ) ,
& V_46 ) ;
if ( F_20 ( V_2 -> V_47 ) )
return F_21 ( V_2 -> V_47 ) ;
F_22 ( & V_2 -> V_44 , V_44 ) ;
V_2 -> V_48 = true ;
F_5 ( L_5 ,
V_44 -> V_42 , V_2 ) ;
} else {
memset ( & V_2 -> V_44 , 0 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_48 = false ;
F_5 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_23 ( struct V_33 * V_2 ,
struct V_49 * V_50 )
{
if ( V_50 == V_2 -> V_47 )
return 0 ;
F_17 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_50 ) {
if ( V_50 -> V_51 != sizeof( struct V_45 ) ||
F_24 ( & V_2 -> V_44 ,
( const struct V_45 * )
V_50 -> V_52 ) )
return - V_53 ;
V_2 -> V_47 = F_25 ( V_50 ) ;
V_2 -> V_48 = true ;
F_5 ( L_5 ,
V_2 -> V_44 . V_42 , V_2 ) ;
} else {
memset ( & V_2 -> V_44 , 0 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_48 = false ;
F_5 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_26 ( struct V_27 * V_28 ,
struct V_33 * V_2 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
int V_34 ;
if ( V_55 == V_19 -> V_57 )
V_2 -> V_58 = V_56 ;
else if ( V_55 == V_19 -> V_59 ) {
struct V_49 * V_44 =
F_27 ( V_10 , V_56 ) ;
V_34 = F_23 ( V_2 , V_44 ) ;
F_17 ( V_44 ) ;
return V_34 ;
}
else if ( V_28 -> V_20 -> V_60 )
return V_28 -> V_20 -> V_60 ( V_28 , V_2 , V_55 , V_56 ) ;
else
return - V_53 ;
return 0 ;
}
static int
F_28 ( struct V_27 * V_28 ,
const struct V_33 * V_2 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_55 == V_19 -> V_57 )
* V_56 = V_2 -> V_58 ;
else if ( V_55 == V_19 -> V_59 )
* V_56 = ( V_2 -> V_47 ) ? V_2 -> V_47 -> V_40 . V_41 : 0 ;
else if ( V_28 -> V_20 -> V_61 )
return V_28 -> V_20 -> V_61 ( V_28 , V_2 , V_55 , V_56 ) ;
else
return - V_53 ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_33 * V_2 )
{
if ( V_2 -> V_58 && ! V_2 -> V_48 ) {
F_5 ( L_7 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
if ( F_30 ( V_28 -> V_10 , V_62 ) &&
F_31 ( V_2 -> V_48 && ! V_2 -> V_47 ) ) {
F_5 ( L_8 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
if ( F_30 ( V_28 -> V_10 , V_62 ) &&
F_31 ( ! V_2 -> V_48 && V_2 -> V_47 ) ) {
F_5 ( L_9 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
if ( V_2 -> V_63 && ! V_2 -> V_58 && ! V_28 -> V_2 -> V_58 ) {
F_5 ( L_10 ,
V_28 -> V_40 . V_41 ) ;
return - V_53 ;
}
return 0 ;
}
struct V_64 *
F_32 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
int V_34 , V_35 = F_33 ( V_30 ) ;
struct V_64 * V_65 ;
V_65 = F_34 ( V_2 , V_30 ) ;
if ( V_65 )
return V_65 ;
V_34 = F_14 ( & V_30 -> V_37 , V_2 -> V_38 ) ;
if ( V_34 )
return F_15 ( V_34 ) ;
V_65 = V_30 -> V_20 -> V_39 ( V_30 ) ;
if ( ! V_65 )
return F_15 ( - V_17 ) ;
V_2 -> V_8 [ V_35 ] = V_65 ;
V_2 -> V_7 [ V_35 ] = V_30 ;
V_65 -> V_2 = V_2 ;
F_5 ( L_11 ,
V_30 -> V_40 . V_41 , V_30 -> V_42 , V_65 , V_2 ) ;
if ( V_65 -> V_28 ) {
struct V_33 * V_36 ;
V_36 = F_11 ( V_2 ,
V_65 -> V_28 ) ;
if ( F_20 ( V_36 ) )
return F_35 ( V_36 ) ;
}
return V_65 ;
}
int F_36 ( struct V_29 * V_30 ,
struct V_64 * V_2 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_55 == V_19 -> V_66 ) {
struct V_67 * V_68 = F_37 ( V_10 , V_56 ) ;
F_38 ( V_2 , V_68 ) ;
if ( V_68 )
F_39 ( V_68 ) ;
} else if ( V_55 == V_19 -> V_69 ) {
struct V_27 * V_28 = F_40 ( V_10 , V_56 ) ;
return F_41 ( V_2 , V_28 ) ;
} else if ( V_55 == V_19 -> V_70 ) {
V_2 -> V_71 = F_42 ( V_56 ) ;
} else if ( V_55 == V_19 -> V_72 ) {
V_2 -> V_73 = F_42 ( V_56 ) ;
} else if ( V_55 == V_19 -> V_74 ) {
V_2 -> V_75 = V_56 ;
} else if ( V_55 == V_19 -> V_76 ) {
V_2 -> V_77 = V_56 ;
} else if ( V_55 == V_19 -> V_78 ) {
V_2 -> V_79 = V_56 ;
} else if ( V_55 == V_19 -> V_80 ) {
V_2 -> V_81 = V_56 ;
} else if ( V_55 == V_19 -> V_82 ) {
V_2 -> V_83 = V_56 ;
} else if ( V_55 == V_19 -> V_84 ) {
V_2 -> V_85 = V_56 ;
} else if ( V_55 == V_19 -> V_86 ) {
V_2 -> V_87 = V_56 ;
} else if ( V_30 -> V_20 -> V_60 ) {
return V_30 -> V_20 -> V_60 ( V_30 , V_2 ,
V_55 , V_56 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
static int
F_43 ( struct V_29 * V_30 ,
const struct V_64 * V_2 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_55 == V_19 -> V_66 ) {
* V_56 = ( V_2 -> V_68 ) ? V_2 -> V_68 -> V_40 . V_41 : 0 ;
} else if ( V_55 == V_19 -> V_69 ) {
* V_56 = ( V_2 -> V_28 ) ? V_2 -> V_28 -> V_40 . V_41 : 0 ;
} else if ( V_55 == V_19 -> V_70 ) {
* V_56 = F_44 ( V_2 -> V_71 ) ;
} else if ( V_55 == V_19 -> V_72 ) {
* V_56 = F_44 ( V_2 -> V_73 ) ;
} else if ( V_55 == V_19 -> V_74 ) {
* V_56 = V_2 -> V_75 ;
} else if ( V_55 == V_19 -> V_76 ) {
* V_56 = V_2 -> V_77 ;
} else if ( V_55 == V_19 -> V_78 ) {
* V_56 = V_2 -> V_79 ;
} else if ( V_55 == V_19 -> V_80 ) {
* V_56 = V_2 -> V_81 ;
} else if ( V_55 == V_19 -> V_82 ) {
* V_56 = V_2 -> V_83 ;
} else if ( V_55 == V_19 -> V_84 ) {
* V_56 = V_2 -> V_85 ;
} else if ( V_55 == V_19 -> V_86 ) {
* V_56 = V_2 -> V_87 ;
} else if ( V_30 -> V_20 -> V_61 ) {
return V_30 -> V_20 -> V_61 ( V_30 , V_2 , V_55 , V_56 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
static bool
F_45 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_64 * V_65 )
{
if ( ! V_30 -> V_2 -> V_28 || ! V_65 -> V_28 )
return false ;
if ( V_30 -> V_2 -> V_28 == V_65 -> V_28 )
return false ;
return true ;
}
static int F_46 ( struct V_29 * V_30 ,
struct V_64 * V_2 )
{
unsigned int V_88 , V_89 ;
int V_34 ;
if ( F_31 ( V_2 -> V_28 && ! V_2 -> V_68 ) ) {
F_5 ( L_12 ) ;
return - V_53 ;
} else if ( F_31 ( V_2 -> V_68 && ! V_2 -> V_28 ) ) {
F_5 ( L_13 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_28 )
return 0 ;
if ( ! ( V_30 -> V_90 & F_47 ( V_2 -> V_28 ) ) ) {
F_5 ( L_14 ) ;
return - V_53 ;
}
V_34 = F_48 ( V_30 , V_2 -> V_68 -> V_91 ) ;
if ( V_34 ) {
F_5 ( L_15 ,
F_49 ( V_2 -> V_68 -> V_91 ) ) ;
return V_34 ;
}
if ( V_2 -> V_75 > V_92 ||
V_2 -> V_71 > V_92 - ( V_93 ) V_2 -> V_75 ||
V_2 -> V_77 > V_92 ||
V_2 -> V_73 > V_92 - ( V_93 ) V_2 -> V_77 ) {
F_5 ( L_16 ,
V_2 -> V_75 , V_2 -> V_77 ,
V_2 -> V_71 , V_2 -> V_73 ) ;
return - V_94 ;
}
V_88 = V_2 -> V_68 -> V_95 << 16 ;
V_89 = V_2 -> V_68 -> V_96 << 16 ;
if ( V_2 -> V_83 > V_88 ||
V_2 -> V_79 > V_88 - V_2 -> V_83 ||
V_2 -> V_85 > V_89 ||
V_2 -> V_81 > V_89 - V_2 -> V_85 ) {
F_5 ( L_17
L_18 ,
V_2 -> V_83 >> 16 , ( ( V_2 -> V_83 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_85 >> 16 , ( ( V_2 -> V_85 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_79 >> 16 , ( ( V_2 -> V_79 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_81 >> 16 , ( ( V_2 -> V_81 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_97 ;
}
if ( F_45 ( V_2 -> V_2 , V_30 , V_2 ) ) {
F_5 ( L_19 ,
V_30 -> V_40 . V_41 , V_30 -> V_42 ) ;
return - V_53 ;
}
return 0 ;
}
struct V_98 *
F_50 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_34 , V_35 ;
struct V_18 * V_19 = & V_25 -> V_10 -> V_12 ;
struct V_98 * V_99 ;
V_34 = F_14 ( & V_19 -> V_100 , V_2 -> V_38 ) ;
if ( V_34 )
return F_15 ( V_34 ) ;
V_35 = F_51 ( V_25 ) ;
if ( V_35 >= V_2 -> V_23 ) {
struct V_24 * * V_101 ;
struct V_98 * * V_102 ;
int V_103 = F_52 ( V_35 + 1 , V_19 -> V_23 ) ;
V_101 = F_53 ( V_2 -> V_3 , V_103 * sizeof( * V_2 -> V_3 ) , V_14 ) ;
if ( ! V_101 )
return F_15 ( - V_17 ) ;
V_2 -> V_3 = V_101 ;
memset ( & V_2 -> V_3 [ V_2 -> V_23 ] , 0 ,
sizeof( * V_2 -> V_3 ) * ( V_103 - V_2 -> V_23 ) ) ;
V_102 = F_53 ( V_2 -> V_4 , V_103 * sizeof( * V_2 -> V_4 ) , V_14 ) ;
if ( ! V_102 )
return F_15 ( - V_17 ) ;
V_2 -> V_4 = V_102 ;
memset ( & V_2 -> V_4 [ V_2 -> V_23 ] , 0 ,
sizeof( * V_2 -> V_4 ) * ( V_103 - V_2 -> V_23 ) ) ;
V_2 -> V_23 = V_103 ;
}
if ( V_2 -> V_4 [ V_35 ] )
return V_2 -> V_4 [ V_35 ] ;
V_99 = V_25 -> V_20 -> V_39 ( V_25 ) ;
if ( ! V_99 )
return F_15 ( - V_17 ) ;
V_2 -> V_4 [ V_35 ] = V_99 ;
V_2 -> V_3 [ V_35 ] = V_25 ;
V_99 -> V_2 = V_2 ;
F_5 ( L_20 ,
V_25 -> V_40 . V_41 , V_99 , V_2 ) ;
if ( V_99 -> V_28 ) {
struct V_33 * V_36 ;
V_36 = F_11 ( V_2 ,
V_99 -> V_28 ) ;
if ( F_20 ( V_36 ) )
return F_35 ( V_36 ) ;
}
return V_99 ;
}
int F_54 ( struct V_24 * V_25 ,
struct V_98 * V_2 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_55 == V_19 -> V_69 ) {
struct V_27 * V_28 = F_40 ( V_10 , V_56 ) ;
return F_55 ( V_2 , V_28 ) ;
} else if ( V_55 == V_19 -> V_104 ) {
return - V_53 ;
} else if ( V_25 -> V_20 -> V_60 ) {
return V_25 -> V_20 -> V_60 ( V_25 ,
V_2 , V_55 , V_56 ) ;
} else {
return - V_53 ;
}
}
static int
F_56 ( struct V_24 * V_25 ,
const struct V_98 * V_2 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_55 == V_19 -> V_69 ) {
* V_56 = ( V_2 -> V_28 ) ? V_2 -> V_28 -> V_40 . V_41 : 0 ;
} else if ( V_55 == V_19 -> V_104 ) {
* V_56 = V_25 -> V_105 ;
} else if ( V_25 -> V_20 -> V_61 ) {
return V_25 -> V_20 -> V_61 ( V_25 ,
V_2 , V_55 , V_56 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
int F_57 ( struct V_106 * V_107 ,
struct V_54 * V_55 , T_1 * V_56 )
{
struct V_9 * V_10 = V_55 -> V_10 ;
int V_34 ;
switch ( V_107 -> type ) {
case V_108 : {
struct V_24 * V_25 = F_58 ( V_107 ) ;
F_31 ( ! F_59 ( & V_10 -> V_12 . V_100 ) ) ;
V_34 = F_56 ( V_25 ,
V_25 -> V_2 , V_55 , V_56 ) ;
break;
}
case V_109 : {
struct V_27 * V_28 = F_60 ( V_107 ) ;
F_31 ( ! F_59 ( & V_28 -> V_37 ) ) ;
V_34 = F_28 ( V_28 ,
V_28 -> V_2 , V_55 , V_56 ) ;
break;
}
case V_110 : {
struct V_29 * V_30 = F_61 ( V_107 ) ;
F_31 ( ! F_59 ( & V_30 -> V_37 ) ) ;
V_34 = F_43 ( V_30 ,
V_30 -> V_2 , V_55 , V_56 ) ;
break;
}
default:
V_34 = - V_53 ;
break;
}
return V_34 ;
}
int
F_41 ( struct V_64 * V_65 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_65 -> V_30 ;
struct V_33 * V_36 ;
if ( V_65 -> V_28 ) {
V_36 = F_11 ( V_65 -> V_2 ,
V_65 -> V_28 ) ;
if ( F_31 ( F_20 ( V_36 ) ) )
return F_21 ( V_36 ) ;
V_36 -> V_111 &= ~ ( 1 << F_33 ( V_30 ) ) ;
}
V_65 -> V_28 = V_28 ;
if ( V_28 ) {
V_36 = F_11 ( V_65 -> V_2 ,
V_28 ) ;
if ( F_20 ( V_36 ) )
return F_21 ( V_36 ) ;
V_36 -> V_111 |= ( 1 << F_33 ( V_30 ) ) ;
}
if ( V_28 )
F_5 ( L_21 ,
V_65 , V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
else
F_5 ( L_22 ,
V_65 ) ;
return 0 ;
}
void
F_38 ( struct V_64 * V_65 ,
struct V_67 * V_68 )
{
if ( V_65 -> V_68 )
F_39 ( V_65 -> V_68 ) ;
if ( V_68 )
F_62 ( V_68 ) ;
V_65 -> V_68 = V_68 ;
if ( V_68 )
F_5 ( L_23 ,
V_68 -> V_40 . V_41 , V_65 ) ;
else
F_5 ( L_24 ,
V_65 ) ;
}
int
F_55 ( struct V_98 * V_112 ,
struct V_27 * V_28 )
{
struct V_33 * V_36 ;
if ( V_112 -> V_28 && V_112 -> V_28 != V_28 ) {
V_36 = F_13 ( V_112 -> V_2 ,
V_112 -> V_28 ) ;
V_36 -> V_113 &=
~ ( 1 << F_51 ( V_112 -> V_25 ) ) ;
}
if ( V_28 ) {
V_36 = F_11 ( V_112 -> V_2 , V_28 ) ;
if ( F_20 ( V_36 ) )
return F_21 ( V_36 ) ;
V_36 -> V_113 |=
1 << F_51 ( V_112 -> V_25 ) ;
}
V_112 -> V_28 = V_28 ;
if ( V_28 )
F_5 ( L_25 ,
V_112 , V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
else
F_5 ( L_26 ,
V_112 ) ;
return 0 ;
}
int
F_63 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_12 ;
struct V_24 * V_25 ;
struct V_98 * V_112 ;
int V_34 ;
V_34 = F_14 ( & V_19 -> V_100 , V_2 -> V_38 ) ;
if ( V_34 )
return V_34 ;
F_5 ( L_27 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 , V_2 ) ;
F_64 (connector, state->dev) {
if ( V_25 -> V_2 -> V_28 != V_28 )
continue;
V_112 = F_50 ( V_2 , V_25 ) ;
if ( F_20 ( V_112 ) )
return F_21 ( V_112 ) ;
}
return 0 ;
}
int
F_65 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
F_31 ( ! F_13 ( V_2 , V_28 ) ) ;
F_66 (plane, state->dev, crtc->state->plane_mask) {
struct V_64 * V_65 =
F_32 ( V_2 , V_30 ) ;
if ( F_20 ( V_65 ) )
return F_21 ( V_65 ) ;
}
return 0 ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_34 ;
V_114:
F_68 ( V_2 -> V_38 ) ;
V_34 = F_69 ( V_2 -> V_10 , V_2 -> V_38 ) ;
if ( V_34 )
goto V_114;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
struct V_29 * V_30 ;
struct V_64 * V_65 ;
struct V_27 * V_28 ;
struct V_33 * V_36 ;
int V_22 , V_34 = 0 ;
F_5 ( L_28 , V_2 ) ;
F_71 (state, plane, plane_state, i) {
V_34 = F_46 ( V_30 , V_65 ) ;
if ( V_34 ) {
F_5 ( L_29 ,
V_30 -> V_40 . V_41 , V_30 -> V_42 ) ;
return V_34 ;
}
}
F_72 (state, crtc, crtc_state, i) {
V_34 = F_29 ( V_28 , V_36 ) ;
if ( V_34 ) {
F_5 ( L_30 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return V_34 ;
}
}
if ( V_19 -> V_20 -> V_115 )
V_34 = V_19 -> V_20 -> V_115 ( V_2 -> V_10 , V_2 ) ;
if ( ! V_2 -> V_11 ) {
F_72 (state, crtc, crtc_state, i) {
if ( F_73 ( V_36 ) ) {
F_5 ( L_31 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
}
}
return V_34 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_12 ;
int V_34 ;
V_34 = F_70 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_5 ( L_32 , V_2 ) ;
return V_19 -> V_20 -> V_116 ( V_2 -> V_10 , V_2 , false ) ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_12 ;
int V_34 ;
V_34 = F_70 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_5 ( L_33 , V_2 ) ;
return V_19 -> V_20 -> V_116 ( V_2 -> V_10 , V_2 , true ) ;
}
static struct V_117 * F_76 (
struct V_9 * V_10 , struct V_118 * V_119 , T_1 V_120 )
{
struct V_117 * V_121 = NULL ;
unsigned long V_122 ;
F_77 ( & V_10 -> V_123 , V_122 ) ;
if ( V_119 -> V_124 < sizeof V_121 -> V_63 ) {
F_78 ( & V_10 -> V_123 , V_122 ) ;
goto V_125;
}
V_119 -> V_124 -= sizeof V_121 -> V_63 ;
F_78 ( & V_10 -> V_123 , V_122 ) ;
V_121 = F_7 ( sizeof *V_121 , V_14 ) ;
if ( V_121 == NULL ) {
F_77 ( & V_10 -> V_123 , V_122 ) ;
V_119 -> V_124 += sizeof V_121 -> V_63 ;
F_78 ( & V_10 -> V_123 , V_122 ) ;
goto V_125;
}
V_121 -> V_63 . V_40 . type = V_126 ;
V_121 -> V_63 . V_40 . V_51 = sizeof V_121 -> V_63 ;
V_121 -> V_63 . V_120 = V_120 ;
V_121 -> V_40 . V_63 = & V_121 -> V_63 . V_40 ;
V_121 -> V_40 . V_119 = V_119 ;
V_121 -> V_40 . V_127 = ( void ( * ) ( struct V_128 * ) ) F_2 ;
V_125:
return V_121 ;
}
static void F_79 ( struct V_9 * V_10 ,
struct V_118 * V_119 , struct V_117 * V_121 )
{
unsigned long V_122 ;
F_77 ( & V_10 -> V_123 , V_122 ) ;
V_119 -> V_124 += sizeof V_121 -> V_63 ;
F_78 ( & V_10 -> V_123 , V_122 ) ;
F_2 ( V_121 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_106 * V_107 , struct V_54 * V_129 ,
T_1 V_130 )
{
struct V_106 * V_131 ;
int V_34 ;
if ( ! F_81 ( V_129 , V_130 , & V_131 ) )
return - V_53 ;
switch ( V_107 -> type ) {
case V_108 : {
struct V_24 * V_25 = F_58 ( V_107 ) ;
struct V_98 * V_99 ;
V_99 = F_50 ( V_2 , V_25 ) ;
if ( F_20 ( V_99 ) ) {
V_34 = F_21 ( V_99 ) ;
break;
}
V_34 = F_54 ( V_25 ,
V_99 , V_129 , V_130 ) ;
break;
}
case V_109 : {
struct V_27 * V_28 = F_60 ( V_107 ) ;
struct V_33 * V_36 ;
V_36 = F_11 ( V_2 , V_28 ) ;
if ( F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ) ;
break;
}
V_34 = F_26 ( V_28 ,
V_36 , V_129 , V_130 ) ;
break;
}
case V_110 : {
struct V_29 * V_30 = F_61 ( V_107 ) ;
struct V_64 * V_65 ;
V_65 = F_32 ( V_2 , V_30 ) ;
if ( F_20 ( V_65 ) ) {
V_34 = F_21 ( V_65 ) ;
break;
}
V_34 = F_36 ( V_30 ,
V_65 , V_129 , V_130 ) ;
break;
}
default:
V_34 = - V_53 ;
break;
}
F_82 ( V_129 , V_131 ) ;
return V_34 ;
}
void F_83 ( struct V_9 * V_10 ,
unsigned V_111 ,
int V_34 )
{
struct V_29 * V_30 ;
F_66 (plane, dev, plane_mask) {
if ( V_34 == 0 ) {
struct V_67 * V_132 = V_30 -> V_2 -> V_68 ;
if ( V_132 )
F_62 ( V_132 ) ;
V_30 -> V_68 = V_132 ;
V_30 -> V_28 = V_30 -> V_2 -> V_28 ;
if ( V_30 -> V_133 )
F_39 ( V_30 -> V_133 ) ;
}
V_30 -> V_133 = NULL ;
}
}
int F_84 ( struct V_9 * V_10 ,
void * V_52 , struct V_118 * V_119 )
{
struct V_134 * V_135 = V_52 ;
T_2 T_3 * V_136 = ( T_2 T_3 * ) ( unsigned long ) ( V_135 -> V_136 ) ;
T_2 T_3 * V_137 = ( T_2 T_3 * ) ( unsigned long ) ( V_135 -> V_137 ) ;
T_2 T_3 * V_138 = ( T_2 T_3 * ) ( unsigned long ) ( V_135 -> V_138 ) ;
T_1 T_3 * V_139 = ( T_1 T_3 * ) ( unsigned long ) ( V_135 -> V_139 ) ;
unsigned int V_140 , V_141 ;
struct V_1 * V_2 ;
struct V_142 V_143 ;
struct V_29 * V_30 ;
struct V_27 * V_28 ;
struct V_33 * V_36 ;
unsigned V_111 ;
int V_34 = 0 ;
unsigned int V_22 , V_144 ;
if ( ! F_30 ( V_10 , V_62 ) )
return - V_53 ;
if ( ! V_119 -> V_145 )
return - V_53 ;
if ( V_135 -> V_122 & ~ V_146 )
return - V_53 ;
if ( V_135 -> V_147 )
return - V_53 ;
if ( ( V_135 -> V_122 & V_148 ) &&
! V_10 -> V_12 . V_149 )
return - V_53 ;
if ( ( V_135 -> V_122 & V_150 ) &&
( V_135 -> V_122 & V_151 ) )
return - V_53 ;
F_85 ( & V_143 , 0 ) ;
V_2 = F_6 ( V_10 ) ;
if ( ! V_2 )
return - V_17 ;
V_2 -> V_38 = & V_143 ;
V_2 -> V_11 = ! ! ( V_135 -> V_122 & V_152 ) ;
V_114:
V_111 = 0 ;
V_140 = 0 ;
V_141 = 0 ;
for ( V_22 = 0 ; V_22 < V_135 -> V_153 ; V_22 ++ ) {
T_2 V_154 , V_155 ;
struct V_106 * V_107 ;
if ( F_86 ( V_154 , V_136 + V_140 ) ) {
V_34 = - V_156 ;
goto V_125;
}
V_107 = F_87 ( V_10 , V_154 , V_157 ) ;
if ( ! V_107 || ! V_107 -> V_158 ) {
V_34 = - V_159 ;
goto V_125;
}
if ( F_86 ( V_155 , V_137 + V_140 ) ) {
V_34 = - V_156 ;
goto V_125;
}
V_140 ++ ;
for ( V_144 = 0 ; V_144 < V_155 ; V_144 ++ ) {
T_2 V_160 ;
T_1 V_130 ;
struct V_54 * V_129 ;
if ( F_86 ( V_160 , V_138 + V_141 ) ) {
V_34 = - V_156 ;
goto V_125;
}
V_129 = F_88 ( V_10 , V_160 ) ;
if ( ! V_129 ) {
V_34 = - V_159 ;
goto V_125;
}
if ( F_89 ( & V_130 ,
V_139 + V_141 ,
sizeof( V_130 ) ) ) {
V_34 = - V_156 ;
goto V_125;
}
V_34 = F_80 ( V_2 , V_107 , V_129 , V_130 ) ;
if ( V_34 )
goto V_125;
V_141 ++ ;
}
if ( V_107 -> type == V_110 && V_155 &&
! ( V_135 -> V_122 & V_150 ) ) {
V_30 = F_61 ( V_107 ) ;
V_111 |= ( 1 << F_33 ( V_30 ) ) ;
V_30 -> V_133 = V_30 -> V_68 ;
}
}
if ( V_135 -> V_122 & V_151 ) {
F_72 (state, crtc, crtc_state, i) {
struct V_117 * V_121 ;
V_121 = F_76 ( V_10 , V_119 , V_135 -> V_120 ) ;
if ( ! V_121 ) {
V_34 = - V_17 ;
goto V_125;
}
V_36 -> V_63 = V_121 ;
}
}
if ( V_135 -> V_122 & V_150 ) {
V_34 = F_70 ( V_2 ) ;
} else if ( V_135 -> V_122 & V_161 ) {
V_34 = F_75 ( V_2 ) ;
} else {
V_34 = F_74 ( V_2 ) ;
}
V_125:
F_83 ( V_10 , V_111 , V_34 ) ;
if ( V_34 && V_135 -> V_122 & V_151 ) {
F_72 (state, crtc, crtc_state, i) {
if ( ! V_36 -> V_63 )
continue;
F_79 ( V_10 , V_119 ,
V_36 -> V_63 ) ;
}
}
if ( V_34 == - V_162 ) {
F_9 ( V_2 ) ;
F_68 ( & V_143 ) ;
goto V_114;
}
if ( V_34 || V_135 -> V_122 & V_150 )
F_10 ( V_2 ) ;
F_90 ( & V_143 ) ;
F_91 ( & V_143 ) ;
return V_34 ;
}
