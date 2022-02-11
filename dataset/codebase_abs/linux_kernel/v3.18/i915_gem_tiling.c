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
T_1 V_11 , V_12 ;
V_11 = F_4 ( V_13 ) ;
V_12 = F_4 ( V_14 ) ;
V_11 &= V_15 | V_16 ;
V_12 &= V_15 | V_16 ;
if ( V_11 == V_12 ) {
V_6 = V_17 ;
V_8 = V_18 ;
} else {
V_6 = V_10 ;
V_8 = V_10 ;
}
} else if ( F_5 ( V_2 ) ) {
V_6 = V_17 ;
V_8 = V_18 ;
} else if ( F_6 ( V_2 ) ) {
V_6 = V_10 ;
V_8 = V_10 ;
} else if ( F_7 ( V_2 ) || ( F_8 ( V_2 ) && ! F_9 ( V_2 ) ) ) {
T_1 V_19 ;
V_19 = F_4 ( V_20 ) ;
switch ( V_19 & V_21 ) {
case V_22 :
case V_23 :
V_6 = V_10 ;
V_8 = V_10 ;
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
V_6 = V_10 ;
V_8 = V_10 ;
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
if ( F_2 ( V_2 ) -> V_9 >= 7 ) {
if ( V_36 / 128 > V_42 )
return false ;
} else if ( F_2 ( V_2 ) -> V_9 >= 4 ) {
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
if ( F_2 ( V_2 ) -> V_9 >= 4 ) {
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
if ( F_2 ( V_46 -> V_47 . V_2 ) -> V_9 >= 4 )
return true ;
if ( F_2 ( V_46 -> V_47 . V_2 ) -> V_9 == 3 ) {
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
args -> V_60 = V_10 ;
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
args -> V_60 = V_10 ;
args -> V_36 = 0 ;
}
}
F_23 ( & V_2 -> V_62 ) ;
if ( args -> V_38 != V_46 -> V_38 ||
args -> V_36 != V_46 -> V_36 ) {
if ( V_46 -> V_63 &&
! F_14 ( V_46 , args -> V_38 ) )
V_54 = F_24 ( V_46 ) ;
if ( V_54 == 0 ) {
V_46 -> V_64 =
V_46 -> V_65 ||
V_46 -> V_66 != V_67 ;
V_46 -> V_38 = args -> V_38 ;
V_46 -> V_36 = args -> V_36 ;
F_25 ( V_46 ) ;
}
}
args -> V_36 = V_46 -> V_36 ;
args -> V_38 = V_46 -> V_38 ;
if ( F_26 ( V_46 ) ) {
if ( V_46 -> V_68 == NULL ) {
V_46 -> V_68 = F_27 ( F_28 ( V_46 -> V_47 . V_37 >> V_69 ) ,
sizeof( long ) , V_70 ) ;
}
} else {
F_29 ( V_46 -> V_68 ) ;
V_46 -> V_68 = NULL ;
}
F_30 ( & V_46 -> V_47 ) ;
F_31 ( & V_2 -> V_62 ) ;
return V_54 ;
}
int
F_32 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_71 * args = V_50 ;
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
args -> V_60 = V_10 ;
break;
default:
F_10 ( L_3 ) ;
}
if ( args -> V_60 == V_30 )
args -> V_60 = V_18 ;
if ( args -> V_60 == V_29 )
args -> V_60 = V_17 ;
F_30 ( & V_46 -> V_47 ) ;
F_31 ( & V_2 -> V_62 ) ;
return 0 ;
}
static void
F_33 ( struct V_72 * V_72 )
{
char V_73 [ 64 ] ;
char * V_74 ;
int V_75 ;
V_74 = F_34 ( V_72 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 += 128 ) {
memcpy ( V_73 , & V_74 [ V_75 ] , 64 ) ;
memcpy ( & V_74 [ V_75 ] , & V_74 [ V_75 + 64 ] , 64 ) ;
memcpy ( & V_74 [ V_75 + 64 ] , V_73 , 64 ) ;
}
F_35 ( V_72 ) ;
}
void
F_36 ( struct V_45 * V_46 )
{
struct V_77 V_78 ;
int V_75 ;
if ( V_46 -> V_68 == NULL )
return;
V_75 = 0 ;
F_37 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_72 * V_72 = F_38 ( & V_78 ) ;
char V_79 = F_39 ( V_72 ) >> 17 ;
if ( ( V_79 & 0x1 ) !=
( F_40 ( V_75 , V_46 -> V_68 ) != 0 ) ) {
F_33 ( V_72 ) ;
F_41 ( V_72 ) ;
}
V_75 ++ ;
}
}
void
F_42 ( struct V_45 * V_46 )
{
struct V_77 V_78 ;
int V_80 = V_46 -> V_47 . V_37 >> V_69 ;
int V_75 ;
if ( V_46 -> V_68 == NULL ) {
V_46 -> V_68 = F_27 ( F_28 ( V_80 ) ,
sizeof( long ) , V_70 ) ;
if ( V_46 -> V_68 == NULL ) {
F_10 ( L_4
L_5 ) ;
return;
}
}
V_75 = 0 ;
F_37 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
if ( F_39 ( F_38 ( & V_78 ) ) & ( 1 << 17 ) )
F_43 ( V_75 , V_46 -> V_68 ) ;
else
F_44 ( V_75 , V_46 -> V_68 ) ;
V_75 ++ ;
}
}
