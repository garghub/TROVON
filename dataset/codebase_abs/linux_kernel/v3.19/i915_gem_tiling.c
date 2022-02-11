void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = V_7 ;
T_1 V_8 = V_7 ;
if ( F_2 ( V_2 ) -> V_9 >= 8 || F_3 ( V_2 ) ) {
V_6 = V_10 ;
V_8 = V_10 ;
} else if ( F_2 ( V_2 ) -> V_9 >= 6 ) {
if ( V_4 -> V_11 ) {
if ( F_4 ( V_12 ) &
V_13 ) {
V_6 = V_14 ;
V_8 = V_15 ;
} else {
V_6 = V_10 ;
V_8 = V_10 ;
}
} else {
T_1 V_16 , V_17 ;
V_16 = F_4 ( V_18 ) ;
V_17 = F_4 ( V_19 ) ;
V_16 &= V_20 | V_21 ;
V_17 &= V_20 | V_21 ;
if ( V_16 == V_17 ) {
V_6 = V_14 ;
V_8 = V_15 ;
} else {
V_6 = V_10 ;
V_8 = V_10 ;
}
}
} else if ( F_5 ( V_2 ) ) {
V_6 = V_14 ;
V_8 = V_15 ;
} else if ( F_6 ( V_2 ) ) {
V_6 = V_10 ;
V_8 = V_10 ;
} else if ( F_7 ( V_2 ) || ( F_8 ( V_2 ) && ! F_9 ( V_2 ) ) ) {
T_1 V_22 ;
V_22 = F_4 ( V_23 ) ;
switch ( V_22 & V_24 ) {
case V_25 :
case V_26 :
V_6 = V_10 ;
V_8 = V_10 ;
break;
case V_27 :
if ( V_22 & V_28 ) {
V_6 = V_14 ;
V_8 = V_15 ;
} else if ( ( V_22 & V_29 ) == 0 ) {
V_6 = V_30 ;
V_8 = V_31 ;
} else {
V_6 = V_32 ;
V_8 = V_33 ;
}
break;
}
if ( F_10 ( V_2 ) ) {
T_1 V_34 = F_4 ( V_35 ) ;
if ( ! ( V_34 & V_36 ) )
V_4 -> V_37 |= V_38 ;
}
if ( V_22 == 0xffffffff ) {
F_11 ( L_1
L_2 ) ;
V_6 = V_7 ;
V_8 = V_7 ;
}
} else {
if ( F_12 ( V_39 ) != F_12 ( V_40 ) ) {
V_6 = V_10 ;
V_8 = V_10 ;
} else {
V_6 = V_14 ;
V_8 = V_15 ;
}
}
V_4 -> V_41 . V_42 = V_6 ;
V_4 -> V_41 . V_43 = V_8 ;
}
static bool
F_13 ( struct V_1 * V_2 , int V_44 , int V_45 , int V_46 )
{
int V_47 ;
if ( V_46 == V_48 )
return true ;
if ( F_6 ( V_2 ) ||
( V_46 == V_49 && F_14 ( V_2 ) ) )
V_47 = 128 ;
else
V_47 = 512 ;
if ( F_2 ( V_2 ) -> V_9 >= 7 ) {
if ( V_44 / 128 > V_50 )
return false ;
} else if ( F_2 ( V_2 ) -> V_9 >= 4 ) {
if ( V_44 / 128 > V_51 )
return false ;
} else {
if ( V_44 > 8192 )
return false ;
if ( F_8 ( V_2 ) ) {
if ( V_45 > V_52 << 20 )
return false ;
} else {
if ( V_45 > V_52 << 19 )
return false ;
}
}
if ( V_44 < V_47 )
return false ;
if ( F_2 ( V_2 ) -> V_9 >= 4 ) {
if ( V_44 & ( V_47 - 1 ) )
return false ;
return true ;
}
if ( V_44 & ( V_44 - 1 ) )
return false ;
return true ;
}
static bool
F_15 ( struct V_53 * V_54 , int V_46 )
{
T_2 V_45 ;
if ( V_46 == V_48 )
return true ;
if ( F_2 ( V_54 -> V_55 . V_2 ) -> V_9 >= 4 )
return true ;
if ( F_2 ( V_54 -> V_55 . V_2 ) -> V_9 == 3 ) {
if ( F_16 ( V_54 ) & ~ V_56 )
return false ;
} else {
if ( F_16 ( V_54 ) & ~ V_57 )
return false ;
}
V_45 = F_17 ( V_54 -> V_55 . V_2 , V_54 -> V_55 . V_45 , V_46 ) ;
if ( F_18 ( V_54 ) != V_45 )
return false ;
if ( F_16 ( V_54 ) & ( V_45 - 1 ) )
return false ;
return true ;
}
int
F_19 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * args = V_58 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_53 * V_54 ;
int V_62 = 0 ;
V_54 = F_20 ( F_21 ( V_2 , V_60 , args -> V_63 ) ) ;
if ( & V_54 -> V_55 == NULL )
return - V_64 ;
if ( ! F_13 ( V_2 ,
args -> V_44 , V_54 -> V_55 . V_45 , args -> V_46 ) ) {
F_22 ( & V_54 -> V_55 ) ;
return - V_65 ;
}
if ( F_23 ( V_54 ) || V_54 -> V_66 ) {
F_22 ( & V_54 -> V_55 ) ;
return - V_67 ;
}
if ( args -> V_46 == V_48 ) {
args -> V_68 = V_10 ;
args -> V_44 = 0 ;
} else {
if ( args -> V_46 == V_69 )
args -> V_68 = V_4 -> V_41 . V_42 ;
else
args -> V_68 = V_4 -> V_41 . V_43 ;
if ( args -> V_68 == V_33 )
args -> V_68 = V_15 ;
if ( args -> V_68 == V_32 )
args -> V_68 = V_14 ;
if ( args -> V_68 == V_7 ) {
args -> V_46 = V_48 ;
args -> V_68 = V_10 ;
args -> V_44 = 0 ;
}
}
F_24 ( & V_2 -> V_70 ) ;
if ( args -> V_46 != V_54 -> V_46 ||
args -> V_44 != V_54 -> V_44 ) {
if ( V_54 -> V_71 &&
! F_15 ( V_54 , args -> V_46 ) )
V_62 = F_25 ( V_54 ) ;
if ( V_62 == 0 ) {
if ( V_54 -> V_72 &&
V_54 -> V_73 == V_74 &&
V_4 -> V_37 & V_38 ) {
if ( args -> V_46 == V_48 )
F_26 ( V_54 ) ;
if ( V_54 -> V_46 == V_48 )
F_27 ( V_54 ) ;
}
V_54 -> V_75 =
V_54 -> V_76 ||
V_54 -> V_77 != V_78 ;
V_54 -> V_46 = args -> V_46 ;
V_54 -> V_44 = args -> V_44 ;
F_28 ( V_54 ) ;
}
}
args -> V_44 = V_54 -> V_44 ;
args -> V_46 = V_54 -> V_46 ;
if ( F_29 ( V_54 ) ) {
if ( V_54 -> V_79 == NULL ) {
V_54 -> V_79 = F_30 ( F_31 ( V_54 -> V_55 . V_45 >> V_80 ) ,
sizeof( long ) , V_81 ) ;
}
} else {
F_32 ( V_54 -> V_79 ) ;
V_54 -> V_79 = NULL ;
}
F_33 ( & V_54 -> V_55 ) ;
F_34 ( & V_2 -> V_70 ) ;
return V_62 ;
}
int
F_35 ( struct V_1 * V_2 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_82 * args = V_58 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_53 * V_54 ;
V_54 = F_20 ( F_21 ( V_2 , V_60 , args -> V_63 ) ) ;
if ( & V_54 -> V_55 == NULL )
return - V_64 ;
F_24 ( & V_2 -> V_70 ) ;
args -> V_46 = V_54 -> V_46 ;
switch ( V_54 -> V_46 ) {
case V_69 :
args -> V_68 = V_4 -> V_41 . V_42 ;
break;
case V_49 :
args -> V_68 = V_4 -> V_41 . V_43 ;
break;
case V_48 :
args -> V_68 = V_10 ;
break;
default:
F_11 ( L_3 ) ;
}
args -> V_83 = args -> V_68 ;
if ( args -> V_68 == V_33 )
args -> V_68 = V_15 ;
if ( args -> V_68 == V_32 )
args -> V_68 = V_14 ;
F_33 ( & V_54 -> V_55 ) ;
F_34 ( & V_2 -> V_70 ) ;
return 0 ;
}
static void
F_36 ( struct V_84 * V_84 )
{
char V_85 [ 64 ] ;
char * V_86 ;
int V_87 ;
V_86 = F_37 ( V_84 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 += 128 ) {
memcpy ( V_85 , & V_86 [ V_87 ] , 64 ) ;
memcpy ( & V_86 [ V_87 ] , & V_86 [ V_87 + 64 ] , 64 ) ;
memcpy ( & V_86 [ V_87 + 64 ] , V_85 , 64 ) ;
}
F_38 ( V_84 ) ;
}
void
F_39 ( struct V_53 * V_54 )
{
struct V_89 V_90 ;
int V_87 ;
if ( V_54 -> V_79 == NULL )
return;
V_87 = 0 ;
F_40 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_84 * V_84 = F_41 ( & V_90 ) ;
char V_91 = F_42 ( V_84 ) >> 17 ;
if ( ( V_91 & 0x1 ) !=
( F_43 ( V_87 , V_54 -> V_79 ) != 0 ) ) {
F_36 ( V_84 ) ;
F_44 ( V_84 ) ;
}
V_87 ++ ;
}
}
void
F_45 ( struct V_53 * V_54 )
{
struct V_89 V_90 ;
int V_92 = V_54 -> V_55 . V_45 >> V_80 ;
int V_87 ;
if ( V_54 -> V_79 == NULL ) {
V_54 -> V_79 = F_30 ( F_31 ( V_92 ) ,
sizeof( long ) , V_81 ) ;
if ( V_54 -> V_79 == NULL ) {
F_11 ( L_4
L_5 ) ;
return;
}
}
V_87 = 0 ;
F_40 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
if ( F_42 ( F_41 ( & V_90 ) ) & ( 1 << 17 ) )
F_46 ( V_87 , V_54 -> V_79 ) ;
else
F_47 ( V_87 , V_54 -> V_79 ) ;
V_87 ++ ;
}
}
