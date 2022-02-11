void
F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 = V_6 ;
T_2 V_7 = V_6 ;
if ( F_2 ( V_2 ) -> V_8 >= 6 ) {
T_2 V_9 , V_10 ;
V_9 = F_3 ( V_11 ) ;
V_10 = F_3 ( V_12 ) ;
V_9 &= V_13 | V_14 ;
V_10 &= V_13 | V_14 ;
if ( V_9 == V_10 ) {
V_5 = V_15 ;
V_7 = V_16 ;
} else {
V_5 = V_17 ;
V_7 = V_17 ;
}
} else if ( F_4 ( V_2 ) ) {
V_5 = V_15 ;
V_7 = V_16 ;
} else if ( F_5 ( V_2 ) ) {
V_5 = V_17 ;
V_7 = V_17 ;
} else if ( F_6 ( V_2 ) || ( F_7 ( V_2 ) && ! F_8 ( V_2 ) ) ) {
T_2 V_18 ;
V_18 = F_3 ( V_19 ) ;
switch ( V_18 & V_20 ) {
case V_21 :
case V_22 :
V_5 = V_17 ;
V_7 = V_17 ;
break;
case V_23 :
if ( V_18 & V_24 ) {
V_5 = V_15 ;
V_7 = V_16 ;
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
F_9 ( L_1
L_2 ) ;
V_5 = V_6 ;
V_7 = V_6 ;
}
} else {
if ( F_10 ( V_30 ) != F_10 ( V_31 ) ) {
V_5 = V_17 ;
V_7 = V_17 ;
} else {
V_5 = V_15 ;
V_7 = V_16 ;
}
}
V_3 -> V_32 . V_33 = V_5 ;
V_3 -> V_32 . V_34 = V_7 ;
}
static bool
F_11 ( struct V_1 * V_2 , int V_35 , int V_36 , int V_37 )
{
int V_38 ;
if ( V_37 == V_39 )
return true ;
if ( F_5 ( V_2 ) ||
( V_37 == V_40 && F_12 ( V_2 ) ) )
V_38 = 128 ;
else
V_38 = 512 ;
if ( F_2 ( V_2 ) -> V_8 >= 4 ) {
if ( V_35 / 128 > V_41 )
return false ;
} else {
if ( V_35 > 8192 )
return false ;
if ( F_7 ( V_2 ) ) {
if ( V_36 > V_42 << 20 )
return false ;
} else {
if ( V_36 > V_42 << 19 )
return false ;
}
}
if ( F_2 ( V_2 ) -> V_8 >= 4 ) {
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
F_13 ( struct V_43 * V_44 , int V_37 )
{
T_3 V_36 ;
if ( V_37 == V_39 )
return true ;
if ( F_2 ( V_44 -> V_45 . V_2 ) -> V_8 >= 4 )
return true ;
if ( F_2 ( V_44 -> V_45 . V_2 ) -> V_8 == 3 ) {
if ( V_44 -> V_46 & ~ V_47 )
return false ;
} else {
if ( V_44 -> V_46 & ~ V_48 )
return false ;
}
if ( F_2 ( V_44 -> V_45 . V_2 ) -> V_8 == 3 )
V_36 = 1024 * 1024 ;
else
V_36 = 512 * 1024 ;
while ( V_36 < V_44 -> V_45 . V_36 )
V_36 <<= 1 ;
if ( V_44 -> V_49 -> V_36 != V_36 )
return false ;
if ( V_44 -> V_46 & ( V_36 - 1 ) )
return false ;
return true ;
}
int
F_14 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * args = V_50 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_43 * V_44 ;
int V_54 = 0 ;
V_44 = F_15 ( F_16 ( V_2 , V_52 , args -> V_55 ) ) ;
if ( & V_44 -> V_45 == NULL )
return - V_56 ;
if ( ! F_11 ( V_2 ,
args -> V_35 , V_44 -> V_45 . V_36 , args -> V_37 ) ) {
F_17 ( & V_44 -> V_45 ) ;
return - V_57 ;
}
if ( V_44 -> V_58 ) {
F_17 ( & V_44 -> V_45 ) ;
return - V_59 ;
}
if ( args -> V_37 == V_39 ) {
args -> V_60 = V_17 ;
args -> V_35 = 0 ;
} else {
if ( args -> V_37 == V_61 )
args -> V_60 = V_3 -> V_32 . V_33 ;
else
args -> V_60 = V_3 -> V_32 . V_34 ;
if ( args -> V_60 == V_29 )
args -> V_60 = V_16 ;
if ( args -> V_60 == V_28 )
args -> V_60 = V_15 ;
if ( args -> V_60 == V_6 ) {
args -> V_37 = V_39 ;
args -> V_60 = V_17 ;
args -> V_35 = 0 ;
}
}
F_18 ( & V_2 -> V_62 ) ;
if ( args -> V_37 != V_44 -> V_37 ||
args -> V_35 != V_44 -> V_35 ) {
F_19 ( V_44 ) ;
V_44 -> V_63 =
V_44 -> V_49 == NULL ||
( V_44 -> V_46 + V_44 -> V_45 . V_36 <= V_3 -> V_32 . V_64 &&
F_13 ( V_44 , args -> V_37 ) ) ;
if ( ! V_44 -> V_63 ) {
T_3 V_65 =
F_20 ( V_2 ,
V_44 -> V_45 . V_36 ,
args -> V_37 ) ;
if ( V_44 -> V_46 & ( V_65 - 1 ) )
V_54 = F_21 ( V_44 ) ;
}
if ( V_54 == 0 ) {
V_44 -> V_66 = true ;
V_44 -> V_37 = args -> V_37 ;
V_44 -> V_35 = args -> V_35 ;
}
}
args -> V_35 = V_44 -> V_35 ;
args -> V_37 = V_44 -> V_37 ;
F_22 ( & V_44 -> V_45 ) ;
F_23 ( & V_2 -> V_62 ) ;
return V_54 ;
}
int
F_24 ( struct V_1 * V_2 , void * V_50 ,
struct V_51 * V_52 )
{
struct V_67 * args = V_50 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_43 * V_44 ;
V_44 = F_15 ( F_16 ( V_2 , V_52 , args -> V_55 ) ) ;
if ( & V_44 -> V_45 == NULL )
return - V_56 ;
F_18 ( & V_2 -> V_62 ) ;
args -> V_37 = V_44 -> V_37 ;
switch ( V_44 -> V_37 ) {
case V_61 :
args -> V_60 = V_3 -> V_32 . V_33 ;
break;
case V_40 :
args -> V_60 = V_3 -> V_32 . V_34 ;
break;
case V_39 :
args -> V_60 = V_17 ;
break;
default:
F_9 ( L_3 ) ;
}
if ( args -> V_60 == V_29 )
args -> V_60 = V_16 ;
if ( args -> V_60 == V_28 )
args -> V_60 = V_15 ;
F_22 ( & V_44 -> V_45 ) ;
F_23 ( & V_2 -> V_62 ) ;
return 0 ;
}
static void
F_25 ( struct V_68 * V_68 )
{
char V_69 [ 64 ] ;
char * V_70 ;
int V_71 ;
V_70 = F_26 ( V_68 ) ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 += 128 ) {
memcpy ( V_69 , & V_70 [ V_71 ] , 64 ) ;
memcpy ( & V_70 [ V_71 ] , & V_70 [ V_71 + 64 ] , 64 ) ;
memcpy ( & V_70 [ V_71 + 64 ] , V_69 , 64 ) ;
}
F_27 ( V_68 ) ;
}
void
F_28 ( struct V_43 * V_44 )
{
int V_73 = V_44 -> V_45 . V_36 >> V_74 ;
int V_71 ;
if ( V_44 -> V_75 == NULL )
return;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
char V_76 = F_29 ( V_44 -> V_77 [ V_71 ] ) >> 17 ;
if ( ( V_76 & 0x1 ) !=
( F_30 ( V_71 , V_44 -> V_75 ) != 0 ) ) {
F_25 ( V_44 -> V_77 [ V_71 ] ) ;
F_31 ( V_44 -> V_77 [ V_71 ] ) ;
}
}
}
void
F_32 ( struct V_43 * V_44 )
{
int V_73 = V_44 -> V_45 . V_36 >> V_74 ;
int V_71 ;
if ( V_44 -> V_75 == NULL ) {
V_44 -> V_75 = F_33 ( F_34 ( V_73 ) *
sizeof( long ) , V_78 ) ;
if ( V_44 -> V_75 == NULL ) {
F_9 ( L_4
L_5 ) ;
return;
}
}
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
if ( F_29 ( V_44 -> V_77 [ V_71 ] ) & ( 1 << 17 ) )
F_35 ( V_71 , V_44 -> V_75 ) ;
else
F_36 ( V_71 , V_44 -> V_75 ) ;
}
}
