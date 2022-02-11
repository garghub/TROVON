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
V_2 -> V_12 = F_4 ( V_10 -> V_13 . V_12 ) ;
V_2 -> V_5 = F_5 ( V_10 -> V_13 . V_14 ,
sizeof( * V_2 -> V_5 ) , V_15 ) ;
if ( ! V_2 -> V_5 )
goto V_16;
V_2 -> V_6 = F_5 ( V_10 -> V_13 . V_14 ,
sizeof( * V_2 -> V_6 ) , V_15 ) ;
if ( ! V_2 -> V_6 )
goto V_16;
V_2 -> V_7 = F_5 ( V_10 -> V_13 . V_17 ,
sizeof( * V_2 -> V_7 ) , V_15 ) ;
if ( ! V_2 -> V_7 )
goto V_16;
V_2 -> V_8 = F_5 ( V_10 -> V_13 . V_17 ,
sizeof( * V_2 -> V_8 ) , V_15 ) ;
if ( ! V_2 -> V_8 )
goto V_16;
V_2 -> V_3 = F_5 ( V_2 -> V_12 ,
sizeof( * V_2 -> V_3 ) ,
V_15 ) ;
if ( ! V_2 -> V_3 )
goto V_16;
V_2 -> V_4 = F_5 ( V_2 -> V_12 ,
sizeof( * V_2 -> V_4 ) ,
V_15 ) ;
if ( ! V_2 -> V_4 )
goto V_16;
V_2 -> V_10 = V_10 ;
F_6 ( L_1 , V_2 ) ;
return 0 ;
V_16:
F_1 ( V_2 ) ;
return - V_18 ;
}
struct V_1 *
F_7 ( struct V_9 * V_10 )
{
struct V_19 * V_20 = & V_10 -> V_13 ;
struct V_1 * V_2 ;
if ( ! V_20 -> V_21 -> V_22 ) {
V_2 = F_8 ( sizeof( * V_2 ) , V_15 ) ;
if ( ! V_2 )
return NULL ;
if ( F_3 ( V_10 , V_2 ) < 0 ) {
F_2 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
return V_20 -> V_21 -> V_22 ( V_10 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
int V_23 ;
F_6 ( L_2 , V_2 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_12 ; V_23 ++ ) {
struct V_24 * V_25 = V_2 -> V_3 [ V_23 ] ;
if ( ! V_25 )
continue;
F_10 ( ! F_11 ( & V_20 -> V_26 ) ) ;
V_25 -> V_21 -> V_27 ( V_25 ,
V_2 -> V_4 [ V_23 ] ) ;
V_2 -> V_3 [ V_23 ] = NULL ;
V_2 -> V_4 [ V_23 ] = NULL ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_14 ; V_23 ++ ) {
struct V_28 * V_29 = V_2 -> V_5 [ V_23 ] ;
if ( ! V_29 )
continue;
V_29 -> V_21 -> V_27 ( V_29 ,
V_2 -> V_6 [ V_23 ] ) ;
V_2 -> V_5 [ V_23 ] = NULL ;
V_2 -> V_6 [ V_23 ] = NULL ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_17 ; V_23 ++ ) {
struct V_30 * V_31 = V_2 -> V_7 [ V_23 ] ;
if ( ! V_31 )
continue;
V_31 -> V_21 -> V_27 ( V_31 ,
V_2 -> V_8 [ V_23 ] ) ;
V_2 -> V_7 [ V_23 ] = NULL ;
V_2 -> V_8 [ V_23 ] = NULL ;
}
}
void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_20 -> V_21 -> V_32 )
V_20 -> V_21 -> V_32 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_19 * V_20 ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
V_20 = & V_10 -> V_13 ;
F_12 ( V_2 ) ;
F_6 ( L_3 , V_2 ) ;
if ( V_20 -> V_21 -> V_33 ) {
V_20 -> V_21 -> V_33 ( V_2 ) ;
} else {
F_1 ( V_2 ) ;
F_2 ( V_2 ) ;
}
}
struct V_34 *
F_14 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_35 , V_36 = F_15 ( V_29 ) ;
struct V_34 * V_37 ;
V_37 = F_16 ( V_2 , V_29 ) ;
if ( V_37 )
return V_37 ;
V_35 = F_17 ( & V_29 -> V_38 , V_2 -> V_39 ) ;
if ( V_35 )
return F_18 ( V_35 ) ;
V_37 = V_29 -> V_21 -> V_40 ( V_29 ) ;
if ( ! V_37 )
return F_18 ( - V_18 ) ;
V_2 -> V_6 [ V_36 ] = V_37 ;
V_2 -> V_5 [ V_36 ] = V_29 ;
V_37 -> V_2 = V_2 ;
F_6 ( L_4 ,
V_29 -> V_41 . V_42 , V_37 , V_2 ) ;
return V_37 ;
}
int F_19 ( struct V_34 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 V_46 ;
if ( V_44 && memcmp ( & V_2 -> V_44 , V_44 , sizeof( * V_44 ) ) == 0 )
return 0 ;
if ( V_2 -> V_47 )
F_20 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_44 ) {
F_21 ( & V_46 , V_44 ) ;
V_2 -> V_47 =
F_22 ( V_2 -> V_29 -> V_10 ,
sizeof( V_46 ) ,
& V_46 ) ;
if ( F_23 ( V_2 -> V_47 ) )
return F_24 ( V_2 -> V_47 ) ;
F_25 ( & V_2 -> V_44 , V_44 ) ;
V_2 -> V_48 = true ;
F_6 ( L_5 ,
V_44 -> V_49 , V_2 ) ;
} else {
memset ( & V_2 -> V_44 , 0 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_48 = false ;
F_6 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_26 ( struct V_34 * V_2 ,
struct V_50 * V_51 )
{
if ( V_51 == V_2 -> V_47 )
return 0 ;
if ( V_2 -> V_47 )
F_20 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_51 ) {
if ( V_51 -> V_52 != sizeof( struct V_45 ) ||
F_27 ( & V_2 -> V_44 ,
( const struct V_45 * )
V_51 -> V_53 ) )
return - V_54 ;
V_2 -> V_47 = F_28 ( V_51 ) ;
V_2 -> V_48 = true ;
F_6 ( L_5 ,
V_2 -> V_44 . V_49 , V_2 ) ;
} else {
memset ( & V_2 -> V_44 , 0 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_48 = false ;
F_6 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_29 ( struct V_28 * V_29 ,
struct V_34 * V_2 , struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
int V_35 ;
if ( V_56 == V_20 -> V_58 )
V_2 -> V_59 = V_57 ;
else if ( V_56 == V_20 -> V_60 ) {
struct V_50 * V_44 =
F_30 ( V_10 , V_57 ) ;
V_35 = F_26 ( V_2 , V_44 ) ;
if ( V_44 )
F_20 ( V_44 ) ;
return V_35 ;
}
else if ( V_29 -> V_21 -> V_61 )
return V_29 -> V_21 -> V_61 ( V_29 , V_2 , V_56 , V_57 ) ;
else
return - V_54 ;
return 0 ;
}
int F_31 ( struct V_28 * V_29 ,
const struct V_34 * V_2 ,
struct V_55 * V_56 , T_1 * V_57 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_56 == V_20 -> V_58 )
* V_57 = V_2 -> V_59 ;
else if ( V_56 == V_20 -> V_60 )
* V_57 = ( V_2 -> V_47 ) ? V_2 -> V_47 -> V_41 . V_42 : 0 ;
else if ( V_29 -> V_21 -> V_62 )
return V_29 -> V_21 -> V_62 ( V_29 , V_2 , V_56 , V_57 ) ;
else
return - V_54 ;
return 0 ;
}
static int F_32 ( struct V_28 * V_29 ,
struct V_34 * V_2 )
{
if ( V_2 -> V_59 && ! V_2 -> V_48 ) {
F_6 ( L_7 ,
V_29 -> V_41 . V_42 ) ;
return - V_54 ;
}
if ( F_33 ( V_29 -> V_10 , V_63 ) &&
F_10 ( V_2 -> V_48 && ! V_2 -> V_47 ) ) {
F_6 ( L_8 ,
V_29 -> V_41 . V_42 ) ;
return - V_54 ;
}
if ( F_33 ( V_29 -> V_10 , V_63 ) &&
F_10 ( ! V_2 -> V_48 && V_2 -> V_47 ) ) {
F_6 ( L_9 ,
V_29 -> V_41 . V_42 ) ;
return - V_54 ;
}
return 0 ;
}
struct V_64 *
F_34 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_35 , V_36 = F_35 ( V_31 ) ;
struct V_64 * V_65 ;
V_65 = F_36 ( V_2 , V_31 ) ;
if ( V_65 )
return V_65 ;
V_35 = F_17 ( & V_31 -> V_38 , V_2 -> V_39 ) ;
if ( V_35 )
return F_18 ( V_35 ) ;
V_65 = V_31 -> V_21 -> V_40 ( V_31 ) ;
if ( ! V_65 )
return F_18 ( - V_18 ) ;
V_2 -> V_8 [ V_36 ] = V_65 ;
V_2 -> V_7 [ V_36 ] = V_31 ;
V_65 -> V_2 = V_2 ;
F_6 ( L_10 ,
V_31 -> V_41 . V_42 , V_65 , V_2 ) ;
if ( V_65 -> V_29 ) {
struct V_34 * V_37 ;
V_37 = F_14 ( V_2 ,
V_65 -> V_29 ) ;
if ( F_23 ( V_37 ) )
return F_37 ( V_37 ) ;
}
return V_65 ;
}
int F_38 ( struct V_30 * V_31 ,
struct V_64 * V_2 , struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_9 * V_10 = V_31 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_56 == V_20 -> V_66 ) {
struct V_67 * V_68 = F_39 ( V_10 , V_57 ) ;
F_40 ( V_2 , V_68 ) ;
if ( V_68 )
F_41 ( V_68 ) ;
} else if ( V_56 == V_20 -> V_69 ) {
struct V_28 * V_29 = F_42 ( V_10 , V_57 ) ;
return F_43 ( V_2 , V_29 ) ;
} else if ( V_56 == V_20 -> V_70 ) {
V_2 -> V_71 = F_44 ( V_57 ) ;
} else if ( V_56 == V_20 -> V_72 ) {
V_2 -> V_73 = F_44 ( V_57 ) ;
} else if ( V_56 == V_20 -> V_74 ) {
V_2 -> V_75 = V_57 ;
} else if ( V_56 == V_20 -> V_76 ) {
V_2 -> V_77 = V_57 ;
} else if ( V_56 == V_20 -> V_78 ) {
V_2 -> V_79 = V_57 ;
} else if ( V_56 == V_20 -> V_80 ) {
V_2 -> V_81 = V_57 ;
} else if ( V_56 == V_20 -> V_82 ) {
V_2 -> V_83 = V_57 ;
} else if ( V_56 == V_20 -> V_84 ) {
V_2 -> V_85 = V_57 ;
} else if ( V_56 == V_20 -> V_86 ) {
V_2 -> V_87 = V_57 ;
} else if ( V_31 -> V_21 -> V_61 ) {
return V_31 -> V_21 -> V_61 ( V_31 , V_2 ,
V_56 , V_57 ) ;
} else {
return - V_54 ;
}
return 0 ;
}
static int
F_45 ( struct V_30 * V_31 ,
const struct V_64 * V_2 ,
struct V_55 * V_56 , T_1 * V_57 )
{
struct V_9 * V_10 = V_31 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_56 == V_20 -> V_66 ) {
* V_57 = ( V_2 -> V_68 ) ? V_2 -> V_68 -> V_41 . V_42 : 0 ;
} else if ( V_56 == V_20 -> V_69 ) {
* V_57 = ( V_2 -> V_29 ) ? V_2 -> V_29 -> V_41 . V_42 : 0 ;
} else if ( V_56 == V_20 -> V_70 ) {
* V_57 = F_46 ( V_2 -> V_71 ) ;
} else if ( V_56 == V_20 -> V_72 ) {
* V_57 = F_46 ( V_2 -> V_73 ) ;
} else if ( V_56 == V_20 -> V_74 ) {
* V_57 = V_2 -> V_75 ;
} else if ( V_56 == V_20 -> V_76 ) {
* V_57 = V_2 -> V_77 ;
} else if ( V_56 == V_20 -> V_78 ) {
* V_57 = V_2 -> V_79 ;
} else if ( V_56 == V_20 -> V_80 ) {
* V_57 = V_2 -> V_81 ;
} else if ( V_56 == V_20 -> V_82 ) {
* V_57 = V_2 -> V_83 ;
} else if ( V_56 == V_20 -> V_84 ) {
* V_57 = V_2 -> V_85 ;
} else if ( V_56 == V_20 -> V_86 ) {
* V_57 = V_2 -> V_87 ;
} else if ( V_31 -> V_21 -> V_62 ) {
return V_31 -> V_21 -> V_62 ( V_31 , V_2 , V_56 , V_57 ) ;
} else {
return - V_54 ;
}
return 0 ;
}
static int F_47 ( struct V_30 * V_31 ,
struct V_64 * V_2 )
{
unsigned int V_88 , V_89 ;
int V_35 ;
if ( F_10 ( V_2 -> V_29 && ! V_2 -> V_68 ) ) {
F_6 ( L_11 ) ;
return - V_54 ;
} else if ( F_10 ( V_2 -> V_68 && ! V_2 -> V_29 ) ) {
F_6 ( L_12 ) ;
return - V_54 ;
}
if ( ! V_2 -> V_29 )
return 0 ;
if ( ! ( V_31 -> V_90 & F_48 ( V_2 -> V_29 ) ) ) {
F_6 ( L_13 ) ;
return - V_54 ;
}
V_35 = F_49 ( V_31 , V_2 -> V_68 -> V_91 ) ;
if ( V_35 ) {
F_6 ( L_14 ,
F_50 ( V_2 -> V_68 -> V_91 ) ) ;
return V_35 ;
}
if ( V_2 -> V_75 > V_92 ||
V_2 -> V_71 > V_92 - ( V_93 ) V_2 -> V_75 ||
V_2 -> V_77 > V_92 ||
V_2 -> V_73 > V_92 - ( V_93 ) V_2 -> V_77 ) {
F_6 ( L_15 ,
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
F_6 ( L_16
L_17 ,
V_2 -> V_83 >> 16 , ( ( V_2 -> V_83 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_85 >> 16 , ( ( V_2 -> V_85 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_79 >> 16 , ( ( V_2 -> V_79 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_81 >> 16 , ( ( V_2 -> V_81 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_97 ;
}
return 0 ;
}
struct V_98 *
F_51 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_35 , V_36 ;
struct V_19 * V_20 = & V_25 -> V_10 -> V_13 ;
struct V_98 * V_99 ;
V_35 = F_17 ( & V_20 -> V_26 , V_2 -> V_39 ) ;
if ( V_35 )
return F_18 ( V_35 ) ;
V_36 = F_52 ( V_25 ) ;
if ( V_36 >= V_2 -> V_12 ) {
F_6 ( L_18 ) ;
return F_18 ( - V_100 ) ;
}
if ( V_2 -> V_4 [ V_36 ] )
return V_2 -> V_4 [ V_36 ] ;
V_99 = V_25 -> V_21 -> V_40 ( V_25 ) ;
if ( ! V_99 )
return F_18 ( - V_18 ) ;
V_2 -> V_4 [ V_36 ] = V_99 ;
V_2 -> V_3 [ V_36 ] = V_25 ;
V_99 -> V_2 = V_2 ;
F_6 ( L_19 ,
V_25 -> V_41 . V_42 , V_99 , V_2 ) ;
if ( V_99 -> V_29 ) {
struct V_34 * V_37 ;
V_37 = F_14 ( V_2 ,
V_99 -> V_29 ) ;
if ( F_23 ( V_37 ) )
return F_37 ( V_37 ) ;
}
return V_99 ;
}
int F_53 ( struct V_24 * V_25 ,
struct V_98 * V_2 , struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_56 == V_20 -> V_69 ) {
struct V_28 * V_29 = F_42 ( V_10 , V_57 ) ;
return F_54 ( V_2 , V_29 ) ;
} else if ( V_56 == V_20 -> V_101 ) {
return - V_54 ;
} else if ( V_25 -> V_21 -> V_61 ) {
return V_25 -> V_21 -> V_61 ( V_25 ,
V_2 , V_56 , V_57 ) ;
} else {
return - V_54 ;
}
}
static int
F_55 ( struct V_24 * V_25 ,
const struct V_98 * V_2 ,
struct V_55 * V_56 , T_1 * V_57 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
if ( V_56 == V_20 -> V_69 ) {
* V_57 = ( V_2 -> V_29 ) ? V_2 -> V_29 -> V_41 . V_42 : 0 ;
} else if ( V_56 == V_20 -> V_101 ) {
* V_57 = V_25 -> V_102 ;
} else if ( V_25 -> V_21 -> V_62 ) {
return V_25 -> V_21 -> V_62 ( V_25 ,
V_2 , V_56 , V_57 ) ;
} else {
return - V_54 ;
}
return 0 ;
}
int F_56 ( struct V_103 * V_104 ,
struct V_55 * V_56 , T_1 * V_57 )
{
struct V_9 * V_10 = V_56 -> V_10 ;
int V_35 ;
switch ( V_104 -> type ) {
case V_105 : {
struct V_24 * V_25 = F_57 ( V_104 ) ;
F_10 ( ! F_11 ( & V_10 -> V_13 . V_26 ) ) ;
V_35 = F_55 ( V_25 ,
V_25 -> V_2 , V_56 , V_57 ) ;
break;
}
case V_106 : {
struct V_28 * V_29 = F_58 ( V_104 ) ;
F_10 ( ! F_11 ( & V_29 -> V_38 ) ) ;
V_35 = F_31 ( V_29 ,
V_29 -> V_2 , V_56 , V_57 ) ;
break;
}
case V_107 : {
struct V_30 * V_31 = F_59 ( V_104 ) ;
F_10 ( ! F_11 ( & V_31 -> V_38 ) ) ;
V_35 = F_45 ( V_31 ,
V_31 -> V_2 , V_56 , V_57 ) ;
break;
}
default:
V_35 = - V_54 ;
break;
}
return V_35 ;
}
int
F_43 ( struct V_64 * V_65 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_65 -> V_31 ;
struct V_34 * V_37 ;
if ( V_65 -> V_29 ) {
V_37 = F_14 ( V_65 -> V_2 ,
V_65 -> V_29 ) ;
if ( F_10 ( F_23 ( V_37 ) ) )
return F_24 ( V_37 ) ;
V_37 -> V_108 &= ~ ( 1 << F_35 ( V_31 ) ) ;
}
V_65 -> V_29 = V_29 ;
if ( V_29 ) {
V_37 = F_14 ( V_65 -> V_2 ,
V_29 ) ;
if ( F_23 ( V_37 ) )
return F_24 ( V_37 ) ;
V_37 -> V_108 |= ( 1 << F_35 ( V_31 ) ) ;
}
if ( V_29 )
F_6 ( L_20 ,
V_65 , V_29 -> V_41 . V_42 ) ;
else
F_6 ( L_21 ,
V_65 ) ;
return 0 ;
}
void
F_40 ( struct V_64 * V_65 ,
struct V_67 * V_68 )
{
if ( V_65 -> V_68 )
F_41 ( V_65 -> V_68 ) ;
if ( V_68 )
F_60 ( V_68 ) ;
V_65 -> V_68 = V_68 ;
if ( V_68 )
F_6 ( L_22 ,
V_68 -> V_41 . V_42 , V_65 ) ;
else
F_6 ( L_23 ,
V_65 ) ;
}
int
F_54 ( struct V_98 * V_109 ,
struct V_28 * V_29 )
{
struct V_34 * V_37 ;
if ( V_29 ) {
V_37 = F_14 ( V_109 -> V_2 , V_29 ) ;
if ( F_23 ( V_37 ) )
return F_24 ( V_37 ) ;
}
V_109 -> V_29 = V_29 ;
if ( V_29 )
F_6 ( L_24 ,
V_109 , V_29 -> V_41 . V_42 ) ;
else
F_6 ( L_25 ,
V_109 ) ;
return 0 ;
}
int
F_61 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_19 * V_20 = & V_2 -> V_10 -> V_13 ;
struct V_24 * V_25 ;
struct V_98 * V_109 ;
int V_35 ;
V_35 = F_17 ( & V_20 -> V_26 , V_2 -> V_39 ) ;
if ( V_35 )
return V_35 ;
F_6 ( L_26 ,
V_29 -> V_41 . V_42 , V_2 ) ;
F_62 (connector, &config->connector_list, head) {
if ( V_25 -> V_2 -> V_29 != V_29 )
continue;
V_109 = F_51 ( V_2 , V_25 ) ;
if ( F_23 ( V_109 ) )
return F_24 ( V_109 ) ;
}
return 0 ;
}
int
F_63 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 ;
F_10 ( ! F_16 ( V_2 , V_29 ) ) ;
F_64 (plane, state->dev, crtc->state->plane_mask) {
struct V_64 * V_65 =
F_34 ( V_2 , V_31 ) ;
if ( F_23 ( V_65 ) )
return F_24 ( V_65 ) ;
}
return 0 ;
}
int
F_65 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_24 * V_25 ;
struct V_98 * V_109 ;
int V_23 , V_110 = 0 ;
F_66 (state, connector, conn_state, i) {
if ( V_109 -> V_29 == V_29 )
V_110 ++ ;
}
F_6 ( L_27 ,
V_2 , V_110 , V_29 -> V_41 . V_42 ) ;
return V_110 ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_35 ;
V_111:
F_68 ( V_2 -> V_39 ) ;
V_35 = F_17 ( & V_2 -> V_10 -> V_13 . V_26 ,
V_2 -> V_39 ) ;
if ( V_35 )
goto V_111;
V_35 = F_69 ( V_2 -> V_10 ,
V_2 -> V_39 ) ;
if ( V_35 )
goto V_111;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_19 * V_20 = & V_10 -> V_13 ;
struct V_30 * V_31 ;
struct V_64 * V_65 ;
struct V_28 * V_29 ;
struct V_34 * V_37 ;
int V_23 , V_35 = 0 ;
F_6 ( L_28 , V_2 ) ;
F_71 (state, plane, plane_state, i) {
V_35 = F_47 ( V_31 , V_65 ) ;
if ( V_35 ) {
F_6 ( L_29 ,
V_31 -> V_41 . V_42 ) ;
return V_35 ;
}
}
F_72 (state, crtc, crtc_state, i) {
V_35 = F_32 ( V_29 , V_37 ) ;
if ( V_35 ) {
F_6 ( L_30 ,
V_29 -> V_41 . V_42 ) ;
return V_35 ;
}
}
if ( V_20 -> V_21 -> V_112 )
V_35 = V_20 -> V_21 -> V_112 ( V_2 -> V_10 , V_2 ) ;
if ( ! V_2 -> V_11 ) {
F_72 (state, crtc, crtc_state, i) {
if ( F_73 ( V_37 ) ) {
F_6 ( L_31 ,
V_29 -> V_41 . V_42 ) ;
return - V_54 ;
}
}
}
return V_35 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_10 -> V_13 ;
int V_35 ;
V_35 = F_70 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_6 ( L_32 , V_2 ) ;
return V_20 -> V_21 -> V_113 ( V_2 -> V_10 , V_2 , false ) ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_10 -> V_13 ;
int V_35 ;
V_35 = F_70 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_6 ( L_33 , V_2 ) ;
return V_20 -> V_21 -> V_113 ( V_2 -> V_10 , V_2 , true ) ;
}
static struct V_114 * F_76 (
struct V_9 * V_10 , struct V_115 * V_116 , T_1 V_117 )
{
struct V_114 * V_118 = NULL ;
unsigned long V_119 ;
F_77 ( & V_10 -> V_120 , V_119 ) ;
if ( V_116 -> V_121 < sizeof V_118 -> V_122 ) {
F_78 ( & V_10 -> V_120 , V_119 ) ;
goto V_123;
}
V_116 -> V_121 -= sizeof V_118 -> V_122 ;
F_78 ( & V_10 -> V_120 , V_119 ) ;
V_118 = F_8 ( sizeof *V_118 , V_15 ) ;
if ( V_118 == NULL ) {
F_77 ( & V_10 -> V_120 , V_119 ) ;
V_116 -> V_121 += sizeof V_118 -> V_122 ;
F_78 ( & V_10 -> V_120 , V_119 ) ;
goto V_123;
}
V_118 -> V_122 . V_41 . type = V_124 ;
V_118 -> V_122 . V_41 . V_52 = sizeof V_118 -> V_122 ;
V_118 -> V_122 . V_117 = V_117 ;
V_118 -> V_41 . V_122 = & V_118 -> V_122 . V_41 ;
V_118 -> V_41 . V_116 = V_116 ;
V_118 -> V_41 . V_125 = ( void ( * ) ( struct V_126 * ) ) F_2 ;
V_123:
return V_118 ;
}
static void F_79 ( struct V_9 * V_10 ,
struct V_115 * V_116 , struct V_114 * V_118 )
{
unsigned long V_119 ;
F_77 ( & V_10 -> V_120 , V_119 ) ;
V_116 -> V_121 += sizeof V_118 -> V_122 ;
F_78 ( & V_10 -> V_120 , V_119 ) ;
F_2 ( V_118 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_103 * V_104 , struct V_55 * V_127 ,
T_1 V_128 )
{
struct V_103 * V_129 ;
int V_35 ;
if ( ! F_81 ( V_127 , V_128 , & V_129 ) )
return - V_54 ;
switch ( V_104 -> type ) {
case V_105 : {
struct V_24 * V_25 = F_57 ( V_104 ) ;
struct V_98 * V_99 ;
V_99 = F_51 ( V_2 , V_25 ) ;
if ( F_23 ( V_99 ) ) {
V_35 = F_24 ( V_99 ) ;
break;
}
V_35 = F_53 ( V_25 ,
V_99 , V_127 , V_128 ) ;
break;
}
case V_106 : {
struct V_28 * V_29 = F_58 ( V_104 ) ;
struct V_34 * V_37 ;
V_37 = F_14 ( V_2 , V_29 ) ;
if ( F_23 ( V_37 ) ) {
V_35 = F_24 ( V_37 ) ;
break;
}
V_35 = F_29 ( V_29 ,
V_37 , V_127 , V_128 ) ;
break;
}
case V_107 : {
struct V_30 * V_31 = F_59 ( V_104 ) ;
struct V_64 * V_65 ;
V_65 = F_34 ( V_2 , V_31 ) ;
if ( F_23 ( V_65 ) ) {
V_35 = F_24 ( V_65 ) ;
break;
}
V_35 = F_38 ( V_31 ,
V_65 , V_127 , V_128 ) ;
break;
}
default:
V_35 = - V_54 ;
break;
}
F_82 ( V_127 , V_129 ) ;
return V_35 ;
}
int F_83 ( struct V_9 * V_10 ,
void * V_53 , struct V_115 * V_116 )
{
struct V_130 * V_131 = V_53 ;
T_2 T_3 * V_132 = ( T_2 T_3 * ) ( unsigned long ) ( V_131 -> V_132 ) ;
T_2 T_3 * V_133 = ( T_2 T_3 * ) ( unsigned long ) ( V_131 -> V_133 ) ;
T_2 T_3 * V_134 = ( T_2 T_3 * ) ( unsigned long ) ( V_131 -> V_134 ) ;
T_1 T_3 * V_135 = ( T_1 T_3 * ) ( unsigned long ) ( V_131 -> V_135 ) ;
unsigned int V_136 , V_137 ;
struct V_1 * V_2 ;
struct V_138 V_139 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_34 * V_37 ;
unsigned V_108 = 0 ;
int V_35 = 0 ;
unsigned int V_23 , V_140 ;
if ( ! F_33 ( V_10 , V_63 ) )
return - V_54 ;
if ( ! V_116 -> V_141 )
return - V_54 ;
if ( V_131 -> V_119 & ~ V_142 )
return - V_54 ;
if ( V_131 -> V_143 )
return - V_54 ;
if ( ( V_131 -> V_119 & V_144 ) &&
! V_10 -> V_13 . V_145 )
return - V_54 ;
if ( ( V_131 -> V_119 & V_146 ) &&
( V_131 -> V_119 & V_147 ) )
return - V_54 ;
F_84 ( & V_139 , 0 ) ;
V_2 = F_7 ( V_10 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_39 = & V_139 ;
V_2 -> V_11 = ! ! ( V_131 -> V_119 & V_148 ) ;
V_111:
V_136 = 0 ;
V_137 = 0 ;
for ( V_23 = 0 ; V_23 < V_131 -> V_149 ; V_23 ++ ) {
T_2 V_150 , V_151 ;
struct V_103 * V_104 ;
if ( F_85 ( V_150 , V_132 + V_136 ) ) {
V_35 = - V_152 ;
goto V_16;
}
V_104 = F_86 ( V_10 , V_150 , V_153 ) ;
if ( ! V_104 || ! V_104 -> V_154 ) {
V_35 = - V_155 ;
goto V_16;
}
if ( V_104 -> type == V_107 ) {
V_31 = F_59 ( V_104 ) ;
V_108 |= ( 1 << F_35 ( V_31 ) ) ;
V_31 -> V_156 = V_31 -> V_68 ;
}
if ( F_85 ( V_151 , V_133 + V_136 ) ) {
V_35 = - V_152 ;
goto V_16;
}
V_136 ++ ;
for ( V_140 = 0 ; V_140 < V_151 ; V_140 ++ ) {
T_2 V_157 ;
T_1 V_128 ;
struct V_55 * V_127 ;
if ( F_85 ( V_157 , V_134 + V_137 ) ) {
V_35 = - V_152 ;
goto V_16;
}
V_127 = F_87 ( V_10 , V_157 ) ;
if ( ! V_127 ) {
V_35 = - V_155 ;
goto V_16;
}
if ( F_88 ( & V_128 ,
V_135 + V_137 ,
sizeof( V_128 ) ) ) {
V_35 = - V_152 ;
goto V_16;
}
V_35 = F_80 ( V_2 , V_104 , V_127 , V_128 ) ;
if ( V_35 )
goto V_16;
V_137 ++ ;
}
}
if ( V_131 -> V_119 & V_147 ) {
F_72 (state, crtc, crtc_state, i) {
struct V_114 * V_118 ;
V_118 = F_76 ( V_10 , V_116 , V_131 -> V_117 ) ;
if ( ! V_118 ) {
V_35 = - V_18 ;
goto V_16;
}
V_37 -> V_122 = V_118 ;
}
}
if ( V_131 -> V_119 & V_146 ) {
V_35 = F_70 ( V_2 ) ;
F_13 ( V_2 ) ;
} else if ( V_131 -> V_119 & V_158 ) {
V_35 = F_75 ( V_2 ) ;
} else {
V_35 = F_74 ( V_2 ) ;
}
F_64 (plane, dev, plane_mask) {
if ( V_35 == 0 ) {
struct V_67 * V_159 = V_31 -> V_2 -> V_68 ;
if ( V_159 )
F_60 ( V_159 ) ;
V_31 -> V_68 = V_159 ;
V_31 -> V_29 = V_31 -> V_2 -> V_29 ;
} else {
V_31 -> V_156 = NULL ;
}
if ( V_31 -> V_156 ) {
F_41 ( V_31 -> V_156 ) ;
V_31 -> V_156 = NULL ;
}
}
F_89 ( & V_139 ) ;
F_90 ( & V_139 ) ;
return V_35 ;
V_16:
if ( V_35 == - V_160 )
goto V_161;
if ( V_131 -> V_119 & V_147 ) {
F_72 (state, crtc, crtc_state, i) {
F_79 ( V_10 , V_116 , V_37 -> V_122 ) ;
V_37 -> V_122 = NULL ;
}
}
F_13 ( V_2 ) ;
F_89 ( & V_139 ) ;
F_90 ( & V_139 ) ;
return V_35 ;
V_161:
F_12 ( V_2 ) ;
F_68 ( & V_139 ) ;
goto V_111;
}
