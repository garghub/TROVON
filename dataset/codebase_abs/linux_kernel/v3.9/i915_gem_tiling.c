void
F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 = V_6 ;
T_2 V_7 = V_6 ;
if ( F_2 ( V_2 ) ) {
V_5 = V_8 ;
V_7 = V_8 ;
} else if ( F_3 ( V_2 ) -> V_9 >= 6 ) {
T_2 V_10 , V_11 ;
V_10 = F_4 ( V_12 ) ;
V_11 = F_4 ( V_13 ) ;
V_10 &= V_14 | V_15 ;
V_11 &= V_14 | V_15 ;
if ( V_10 == V_11 ) {
V_5 = V_16 ;
V_7 = V_17 ;
} else {
V_5 = V_8 ;
V_7 = V_8 ;
}
} else if ( F_5 ( V_2 ) ) {
V_5 = V_16 ;
V_7 = V_17 ;
} else if ( F_6 ( V_2 ) ) {
V_5 = V_8 ;
V_7 = V_8 ;
} else if ( F_7 ( V_2 ) || ( F_8 ( V_2 ) && ! F_9 ( V_2 ) ) ) {
T_2 V_18 ;
V_18 = F_4 ( V_19 ) ;
switch ( V_18 & V_20 ) {
case V_21 :
case V_22 :
V_5 = V_8 ;
V_7 = V_8 ;
break;
case V_23 :
if ( V_18 & V_24 ) {
V_5 = V_16 ;
V_7 = V_17 ;
} else if ( ( V_18 & V_25 ) == 0 ) {
V_5 = V_26 ;
V_7 = V_27 ;
} else {
V_5 = V_28 ;
V_7 = V_29 ;
}
break;
}
if ( V_18 == 0xffffffff ) {
F_10 ( L_1
L_2 ) ;
V_5 = V_6 ;
V_7 = V_6 ;
}
} else {
if ( F_11 ( V_30 ) != F_11 ( V_31 ) ) {
V_5 = V_8 ;
V_7 = V_8 ;
} else {
V_5 = V_16 ;
V_7 = V_17 ;
}
}
V_3 -> V_32 . V_33 = V_5 ;
V_3 -> V_32 . V_34 = V_7 ;
}
static bool
F_12 ( struct V_1 * V_2 , int V_35 , int V_36 , int V_37 )
{
int V_38 ;
if ( V_37 == V_39 )
return true ;
if ( F_6 ( V_2 ) ||
( V_37 == V_40 && F_13 ( V_2 ) ) )
V_38 = 128 ;
else
V_38 = 512 ;
if ( F_3 ( V_2 ) -> V_9 >= 4 ) {
if ( V_35 / 128 > V_41 )
return false ;
} else {
if ( V_35 > 8192 )
return false ;
if ( F_8 ( V_2 ) ) {
if ( V_36 > V_42 << 20 )
return false ;
} else {
if ( V_36 > V_42 << 19 )
return false ;
}
}
if ( F_3 ( V_2 ) -> V_9 >= 4 ) {
if ( V_35 & ( V_38 - 1 ) )
return false ;
return true ;
}
if ( V_35 < V_38 )
return false ;
if ( V_35 & ( V_35 - 1 ) )
return false ;
return true ;
}
static bool
F_14 ( struct V_43 * V_44 , int V_37 )
{
T_3 V_36 ;
if ( V_37 == V_39 )
return true ;
if ( F_3 ( V_44 -> V_45 . V_2 ) -> V_9 >= 4 )
return true ;
if ( F_3 ( V_44 -> V_45 . V_2 ) -> V_9 == 3 ) {
if ( V_44 -> V_46 & ~ V_47 )
return false ;
} else {
if ( V_44 -> V_46 & ~ V_48 )
return false ;
}
V_36 = F_15 ( V_44 -> V_45 . V_2 , V_44 -> V_45 . V_36 , V_37 ) ;
if ( V_44 -> V_49 -> V_36 != V_36 )
return false ;
if ( V_44 -> V_46 & ( V_36 - 1 ) )
return false ;
return true ;
}
int
F_16 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * args = V_50 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_43 * V_44 ;
int V_54 = 0 ;
V_44 = F_17 ( F_18 ( V_2 , V_52 , args -> V_55 ) ) ;
if ( & V_44 -> V_45 == NULL )
return - V_56 ;
if ( ! F_12 ( V_2 ,
args -> V_35 , V_44 -> V_45 . V_36 , args -> V_37 ) ) {
F_19 ( & V_44 -> V_45 ) ;
return - V_57 ;
}
if ( V_44 -> V_58 ) {
F_19 ( & V_44 -> V_45 ) ;
return - V_59 ;
}
if ( args -> V_37 == V_39 ) {
args -> V_60 = V_8 ;
args -> V_35 = 0 ;
} else {
if ( args -> V_37 == V_61 )
args -> V_60 = V_3 -> V_32 . V_33 ;
else
args -> V_60 = V_3 -> V_32 . V_34 ;
if ( args -> V_60 == V_29 )
args -> V_60 = V_17 ;
if ( args -> V_60 == V_28 )
args -> V_60 = V_16 ;
if ( args -> V_60 == V_6 ) {
args -> V_37 = V_39 ;
args -> V_60 = V_8 ;
args -> V_35 = 0 ;
}
}
F_20 ( & V_2 -> V_62 ) ;
if ( args -> V_37 != V_44 -> V_37 ||
args -> V_35 != V_44 -> V_35 ) {
V_44 -> V_63 =
V_44 -> V_49 == NULL ||
( V_44 -> V_46 + V_44 -> V_45 . V_36 <= V_3 -> V_64 . V_65 &&
F_14 ( V_44 , args -> V_37 ) ) ;
if ( ! V_44 -> V_63 ) {
T_3 V_66 =
F_21 ( V_2 , V_44 -> V_45 . V_36 ,
args -> V_37 ,
false ) ;
if ( V_44 -> V_46 & ( V_66 - 1 ) )
V_54 = F_22 ( V_44 ) ;
}
if ( V_54 == 0 ) {
V_44 -> V_67 =
V_44 -> V_68 ||
V_44 -> V_69 != V_70 ;
V_44 -> V_37 = args -> V_37 ;
V_44 -> V_35 = args -> V_35 ;
F_23 ( V_44 ) ;
}
}
args -> V_35 = V_44 -> V_35 ;
args -> V_37 = V_44 -> V_37 ;
if ( F_24 ( V_44 ) ) {
if ( V_44 -> V_71 == NULL ) {
V_44 -> V_71 = F_25 ( F_26 ( V_44 -> V_45 . V_36 >> V_72 ) *
sizeof( long ) , V_73 ) ;
}
} else {
F_27 ( V_44 -> V_71 ) ;
V_44 -> V_71 = NULL ;
}
F_28 ( & V_44 -> V_45 ) ;
F_29 ( & V_2 -> V_62 ) ;
return V_54 ;
}
int
F_30 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_74 * args = V_50 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_43 * V_44 ;
V_44 = F_17 ( F_18 ( V_2 , V_52 , args -> V_55 ) ) ;
if ( & V_44 -> V_45 == NULL )
return - V_56 ;
F_20 ( & V_2 -> V_62 ) ;
args -> V_37 = V_44 -> V_37 ;
switch ( V_44 -> V_37 ) {
case V_61 :
args -> V_60 = V_3 -> V_32 . V_33 ;
break;
case V_40 :
args -> V_60 = V_3 -> V_32 . V_34 ;
break;
case V_39 :
args -> V_60 = V_8 ;
break;
default:
F_10 ( L_3 ) ;
}
if ( args -> V_60 == V_29 )
args -> V_60 = V_17 ;
if ( args -> V_60 == V_28 )
args -> V_60 = V_16 ;
F_28 ( & V_44 -> V_45 ) ;
F_29 ( & V_2 -> V_62 ) ;
return 0 ;
}
static void
F_31 ( struct V_75 * V_75 )
{
char V_76 [ 64 ] ;
char * V_77 ;
int V_78 ;
V_77 = F_32 ( V_75 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 += 128 ) {
memcpy ( V_76 , & V_77 [ V_78 ] , 64 ) ;
memcpy ( & V_77 [ V_78 ] , & V_77 [ V_78 + 64 ] , 64 ) ;
memcpy ( & V_77 [ V_78 + 64 ] , V_76 , 64 ) ;
}
F_33 ( V_75 ) ;
}
void
F_34 ( struct V_43 * V_44 )
{
struct V_80 * V_81 ;
int V_82 = V_44 -> V_45 . V_36 >> V_72 ;
int V_78 ;
if ( V_44 -> V_71 == NULL )
return;
F_35 (obj->pages->sgl, sg, page_count, i) {
struct V_75 * V_75 = F_36 ( V_81 ) ;
char V_83 = F_37 ( V_75 ) >> 17 ;
if ( ( V_83 & 0x1 ) !=
( F_38 ( V_78 , V_44 -> V_71 ) != 0 ) ) {
F_31 ( V_75 ) ;
F_39 ( V_75 ) ;
}
}
}
void
F_40 ( struct V_43 * V_44 )
{
struct V_80 * V_81 ;
int V_82 = V_44 -> V_45 . V_36 >> V_72 ;
int V_78 ;
if ( V_44 -> V_71 == NULL ) {
V_44 -> V_71 = F_25 ( F_26 ( V_82 ) *
sizeof( long ) , V_73 ) ;
if ( V_44 -> V_71 == NULL ) {
F_10 ( L_4
L_5 ) ;
return;
}
}
F_35 (obj->pages->sgl, sg, page_count, i) {
struct V_75 * V_75 = F_36 ( V_81 ) ;
if ( F_37 ( V_75 ) & ( 1 << 17 ) )
F_41 ( V_78 , V_44 -> V_71 ) ;
else
F_42 ( V_78 , V_44 -> V_71 ) ;
}
}
