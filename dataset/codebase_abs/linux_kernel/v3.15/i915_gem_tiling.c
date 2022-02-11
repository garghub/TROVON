void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = V_7 ;
T_1 V_8 = V_7 ;
if ( F_2 ( V_2 ) ) {
V_6 = V_9 ;
V_8 = V_9 ;
} else if ( F_3 ( V_2 ) -> V_10 >= 6 ) {
T_1 V_11 , V_12 ;
V_11 = F_4 ( V_13 ) ;
V_12 = F_4 ( V_14 ) ;
V_11 &= V_15 | V_16 ;
V_12 &= V_15 | V_16 ;
if ( V_11 == V_12 ) {
V_6 = V_17 ;
V_8 = V_18 ;
} else {
V_6 = V_9 ;
V_8 = V_9 ;
}
} else if ( F_5 ( V_2 ) ) {
V_6 = V_17 ;
V_8 = V_18 ;
} else if ( F_6 ( V_2 ) ) {
V_6 = V_9 ;
V_8 = V_9 ;
} else if ( F_7 ( V_2 ) || ( F_8 ( V_2 ) && ! F_9 ( V_2 ) ) ) {
T_1 V_19 ;
V_19 = F_4 ( V_20 ) ;
switch ( V_19 & V_21 ) {
case V_22 :
case V_23 :
V_6 = V_9 ;
V_8 = V_9 ;
break;
case V_24 :
if ( V_19 & V_25 ) {
V_6 = V_17 ;
V_8 = V_18 ;
} else if ( ( V_19 & V_26 ) == 0 ) {
V_6 = V_27 ;
V_8 = V_28 ;
} else {
V_6 = V_29 ;
V_8 = V_30 ;
}
break;
}
if ( V_19 == 0xffffffff ) {
F_10 ( L_1
L_2 ) ;
V_6 = V_7 ;
V_8 = V_7 ;
}
} else {
if ( F_11 ( V_31 ) != F_11 ( V_32 ) ) {
V_6 = V_9 ;
V_8 = V_9 ;
} else {
V_6 = V_17 ;
V_8 = V_18 ;
}
}
V_4 -> V_33 . V_34 = V_6 ;
V_4 -> V_33 . V_35 = V_8 ;
}
static bool
F_12 ( struct V_1 * V_2 , int V_36 , int V_37 , int V_38 )
{
int V_39 ;
if ( V_38 == V_40 )
return true ;
if ( F_6 ( V_2 ) ||
( V_38 == V_41 && F_13 ( V_2 ) ) )
V_39 = 128 ;
else
V_39 = 512 ;
if ( F_3 ( V_2 ) -> V_10 >= 7 ) {
if ( V_36 / 128 > V_42 )
return false ;
} else if ( F_3 ( V_2 ) -> V_10 >= 4 ) {
if ( V_36 / 128 > V_43 )
return false ;
} else {
if ( V_36 > 8192 )
return false ;
if ( F_8 ( V_2 ) ) {
if ( V_37 > V_44 << 20 )
return false ;
} else {
if ( V_37 > V_44 << 19 )
return false ;
}
}
if ( V_36 < V_39 )
return false ;
if ( F_3 ( V_2 ) -> V_10 >= 4 ) {
if ( V_36 & ( V_39 - 1 ) )
return false ;
return true ;
}
if ( V_36 & ( V_36 - 1 ) )
return false ;
return true ;
}
static bool
F_14 ( struct V_45 * V_46 , int V_38 )
{
T_2 V_37 ;
if ( V_38 == V_40 )
return true ;
if ( F_3 ( V_46 -> V_47 . V_2 ) -> V_10 >= 4 )
return true ;
if ( F_3 ( V_46 -> V_47 . V_2 ) -> V_10 == 3 ) {
if ( F_15 ( V_46 ) & ~ V_48 )
return false ;
} else {
if ( F_15 ( V_46 ) & ~ V_49 )
return false ;
}
V_37 = F_16 ( V_46 -> V_47 . V_2 , V_46 -> V_47 . V_37 , V_38 ) ;
if ( F_17 ( V_46 ) != V_37 )
return false ;
if ( F_15 ( V_46 ) & ( V_37 - 1 ) )
return false ;
return true ;
}
int
F_18 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * args = V_50 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_45 * V_46 ;
int V_54 = 0 ;
V_46 = F_19 ( F_20 ( V_2 , V_52 , args -> V_55 ) ) ;
if ( & V_46 -> V_47 == NULL )
return - V_56 ;
if ( ! F_12 ( V_2 ,
args -> V_36 , V_46 -> V_47 . V_37 , args -> V_38 ) ) {
F_21 ( & V_46 -> V_47 ) ;
return - V_57 ;
}
if ( F_22 ( V_46 ) || V_46 -> V_58 ) {
F_21 ( & V_46 -> V_47 ) ;
return - V_59 ;
}
if ( args -> V_38 == V_40 ) {
args -> V_60 = V_9 ;
args -> V_36 = 0 ;
} else {
if ( args -> V_38 == V_61 )
args -> V_60 = V_4 -> V_33 . V_34 ;
else
args -> V_60 = V_4 -> V_33 . V_35 ;
if ( args -> V_60 == V_30 )
args -> V_60 = V_18 ;
if ( args -> V_60 == V_29 )
args -> V_60 = V_17 ;
if ( args -> V_60 == V_7 ) {
args -> V_38 = V_40 ;
args -> V_60 = V_9 ;
args -> V_36 = 0 ;
}
}
F_23 ( & V_2 -> V_62 ) ;
if ( args -> V_38 != V_46 -> V_38 ||
args -> V_36 != V_46 -> V_36 ) {
V_46 -> V_63 =
! F_24 ( V_46 ) ||
( F_15 ( V_46 ) +
V_46 -> V_47 . V_37 <= V_4 -> V_64 . V_65 &&
F_14 ( V_46 , args -> V_38 ) ) ;
if ( ! V_46 -> V_63 ) {
T_2 V_66 =
F_25 ( V_2 , V_46 -> V_47 . V_37 ,
args -> V_38 ,
false ) ;
if ( F_15 ( V_46 ) & ( V_66 - 1 ) )
V_54 = F_26 ( V_46 ) ;
}
if ( V_54 == 0 ) {
V_46 -> V_67 =
V_46 -> V_68 ||
V_46 -> V_69 != V_70 ;
V_46 -> V_38 = args -> V_38 ;
V_46 -> V_36 = args -> V_36 ;
F_27 ( V_46 ) ;
}
}
args -> V_36 = V_46 -> V_36 ;
args -> V_38 = V_46 -> V_38 ;
if ( F_28 ( V_46 ) ) {
if ( V_46 -> V_71 == NULL ) {
V_46 -> V_71 = F_29 ( F_30 ( V_46 -> V_47 . V_37 >> V_72 ) ,
sizeof( long ) , V_73 ) ;
}
} else {
F_31 ( V_46 -> V_71 ) ;
V_46 -> V_71 = NULL ;
}
F_32 ( & V_46 -> V_47 ) ;
F_33 ( & V_2 -> V_62 ) ;
return V_54 ;
}
int
F_34 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_74 * args = V_50 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_45 * V_46 ;
V_46 = F_19 ( F_20 ( V_2 , V_52 , args -> V_55 ) ) ;
if ( & V_46 -> V_47 == NULL )
return - V_56 ;
F_23 ( & V_2 -> V_62 ) ;
args -> V_38 = V_46 -> V_38 ;
switch ( V_46 -> V_38 ) {
case V_61 :
args -> V_60 = V_4 -> V_33 . V_34 ;
break;
case V_41 :
args -> V_60 = V_4 -> V_33 . V_35 ;
break;
case V_40 :
args -> V_60 = V_9 ;
break;
default:
F_10 ( L_3 ) ;
}
if ( args -> V_60 == V_30 )
args -> V_60 = V_18 ;
if ( args -> V_60 == V_29 )
args -> V_60 = V_17 ;
F_32 ( & V_46 -> V_47 ) ;
F_33 ( & V_2 -> V_62 ) ;
return 0 ;
}
static void
F_35 ( struct V_75 * V_75 )
{
char V_76 [ 64 ] ;
char * V_77 ;
int V_78 ;
V_77 = F_36 ( V_75 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 += 128 ) {
memcpy ( V_76 , & V_77 [ V_78 ] , 64 ) ;
memcpy ( & V_77 [ V_78 ] , & V_77 [ V_78 + 64 ] , 64 ) ;
memcpy ( & V_77 [ V_78 + 64 ] , V_76 , 64 ) ;
}
F_37 ( V_75 ) ;
}
void
F_38 ( struct V_45 * V_46 )
{
struct V_80 V_81 ;
int V_78 ;
if ( V_46 -> V_71 == NULL )
return;
V_78 = 0 ;
F_39 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_75 * V_75 = F_40 ( & V_81 ) ;
char V_82 = F_41 ( V_75 ) >> 17 ;
if ( ( V_82 & 0x1 ) !=
( F_42 ( V_78 , V_46 -> V_71 ) != 0 ) ) {
F_35 ( V_75 ) ;
F_43 ( V_75 ) ;
}
V_78 ++ ;
}
}
void
F_44 ( struct V_45 * V_46 )
{
struct V_80 V_81 ;
int V_83 = V_46 -> V_47 . V_37 >> V_72 ;
int V_78 ;
if ( V_46 -> V_71 == NULL ) {
V_46 -> V_71 = F_29 ( F_30 ( V_83 ) ,
sizeof( long ) , V_73 ) ;
if ( V_46 -> V_71 == NULL ) {
F_10 ( L_4
L_5 ) ;
return;
}
}
V_78 = 0 ;
F_39 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
if ( F_41 ( F_40 ( & V_81 ) ) & ( 1 << 17 ) )
F_45 ( V_78 , V_46 -> V_71 ) ;
else
F_46 ( V_78 , V_46 -> V_71 ) ;
V_78 ++ ;
}
}
