void
F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 = V_6 ;
T_2 V_7 = V_6 ;
if ( F_2 ( V_2 ) -> V_8 >= 6 ) {
V_5 = V_9 ;
V_7 = V_9 ;
} else if ( F_3 ( V_2 ) ) {
V_5 = V_10 ;
V_7 = V_11 ;
} else if ( F_4 ( V_2 ) ) {
V_5 = V_9 ;
V_7 = V_9 ;
} else if ( F_5 ( V_2 ) ) {
T_2 V_12 ;
V_12 = F_6 ( V_13 ) ;
switch ( V_12 & V_14 ) {
case V_15 :
case V_16 :
V_5 = V_9 ;
V_7 = V_9 ;
break;
case V_17 :
if ( V_12 & V_18 ) {
V_5 = V_10 ;
V_7 = V_11 ;
} else if ( ( V_12 & V_19 ) == 0 ) {
V_5 = V_20 ;
V_7 = V_21 ;
} else {
V_5 = V_22 ;
V_7 = V_23 ;
}
break;
}
if ( V_12 == 0xffffffff ) {
F_7 ( L_1
L_2 ) ;
V_5 = V_6 ;
V_7 = V_6 ;
}
} else {
if ( F_8 ( V_24 ) != F_8 ( V_25 ) ) {
V_5 = V_9 ;
V_7 = V_9 ;
} else {
V_5 = V_10 ;
V_7 = V_11 ;
}
}
V_3 -> V_26 . V_27 = V_5 ;
V_3 -> V_26 . V_28 = V_7 ;
}
static bool
F_9 ( struct V_1 * V_2 , int V_29 , int V_30 , int V_31 )
{
int V_32 ;
if ( V_31 == V_33 )
return true ;
if ( F_4 ( V_2 ) ||
( V_31 == V_34 && F_10 ( V_2 ) ) )
V_32 = 128 ;
else
V_32 = 512 ;
if ( F_2 ( V_2 ) -> V_8 >= 4 ) {
if ( V_29 / 128 > V_35 )
return false ;
} else {
if ( V_29 > 8192 )
return false ;
if ( F_11 ( V_2 ) ) {
if ( V_30 > V_36 << 20 )
return false ;
} else {
if ( V_30 > V_36 << 19 )
return false ;
}
}
if ( F_2 ( V_2 ) -> V_8 >= 4 ) {
if ( V_29 & ( V_32 - 1 ) )
return false ;
return true ;
}
if ( V_29 < V_32 )
return false ;
if ( V_29 & ( V_29 - 1 ) )
return false ;
return true ;
}
static bool
F_12 ( struct V_37 * V_38 , int V_31 )
{
T_3 V_30 ;
if ( V_31 == V_33 )
return true ;
if ( F_2 ( V_38 -> V_39 . V_2 ) -> V_8 >= 4 )
return true ;
if ( F_2 ( V_38 -> V_39 . V_2 ) -> V_8 == 3 ) {
if ( V_38 -> V_40 & ~ V_41 )
return false ;
} else {
if ( V_38 -> V_40 & ~ V_42 )
return false ;
}
if ( F_2 ( V_38 -> V_39 . V_2 ) -> V_8 == 3 )
V_30 = 1024 * 1024 ;
else
V_30 = 512 * 1024 ;
while ( V_30 < V_38 -> V_39 . V_30 )
V_30 <<= 1 ;
if ( V_38 -> V_43 -> V_30 != V_30 )
return false ;
if ( V_38 -> V_40 & ( V_30 - 1 ) )
return false ;
return true ;
}
int
F_13 ( struct V_1 * V_2 , void * V_44 ,
struct V_45 * V_46 )
{
struct V_47 * args = V_44 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_37 * V_38 ;
int V_48 = 0 ;
V_38 = F_14 ( F_15 ( V_2 , V_46 , args -> V_49 ) ) ;
if ( & V_38 -> V_39 == NULL )
return - V_50 ;
if ( ! F_9 ( V_2 ,
args -> V_29 , V_38 -> V_39 . V_30 , args -> V_31 ) ) {
F_16 ( & V_38 -> V_39 ) ;
return - V_51 ;
}
if ( V_38 -> V_52 ) {
F_16 ( & V_38 -> V_39 ) ;
return - V_53 ;
}
if ( args -> V_31 == V_33 ) {
args -> V_54 = V_9 ;
args -> V_29 = 0 ;
} else {
if ( args -> V_31 == V_55 )
args -> V_54 = V_3 -> V_26 . V_27 ;
else
args -> V_54 = V_3 -> V_26 . V_28 ;
if ( args -> V_54 == V_23 )
args -> V_54 = V_11 ;
if ( args -> V_54 == V_22 )
args -> V_54 = V_10 ;
if ( args -> V_54 == V_6 ) {
args -> V_31 = V_33 ;
args -> V_54 = V_9 ;
args -> V_29 = 0 ;
}
}
F_17 ( & V_2 -> V_56 ) ;
if ( args -> V_31 != V_38 -> V_31 ||
args -> V_29 != V_38 -> V_29 ) {
F_18 ( V_38 ) ;
V_38 -> V_57 =
V_38 -> V_43 == NULL ||
( V_38 -> V_40 + V_38 -> V_39 . V_30 <= V_3 -> V_26 . V_58 &&
F_12 ( V_38 , args -> V_31 ) ) ;
if ( ! V_38 -> V_57 ) {
T_3 V_59 =
F_19 ( V_2 ,
V_38 -> V_39 . V_30 ,
args -> V_31 ) ;
if ( V_38 -> V_40 & ( V_59 - 1 ) )
V_48 = F_20 ( V_38 ) ;
}
if ( V_48 == 0 ) {
V_38 -> V_60 = true ;
V_38 -> V_31 = args -> V_31 ;
V_38 -> V_29 = args -> V_29 ;
}
}
args -> V_29 = V_38 -> V_29 ;
args -> V_31 = V_38 -> V_31 ;
F_21 ( & V_38 -> V_39 ) ;
F_22 ( & V_2 -> V_56 ) ;
return V_48 ;
}
int
F_23 ( struct V_1 * V_2 , void * V_44 ,
struct V_45 * V_46 )
{
struct V_61 * args = V_44 ;
T_1 * V_3 = V_2 -> V_4 ;
struct V_37 * V_38 ;
V_38 = F_14 ( F_15 ( V_2 , V_46 , args -> V_49 ) ) ;
if ( & V_38 -> V_39 == NULL )
return - V_50 ;
F_17 ( & V_2 -> V_56 ) ;
args -> V_31 = V_38 -> V_31 ;
switch ( V_38 -> V_31 ) {
case V_55 :
args -> V_54 = V_3 -> V_26 . V_27 ;
break;
case V_34 :
args -> V_54 = V_3 -> V_26 . V_28 ;
break;
case V_33 :
args -> V_54 = V_9 ;
break;
default:
F_7 ( L_3 ) ;
}
if ( args -> V_54 == V_23 )
args -> V_54 = V_11 ;
if ( args -> V_54 == V_22 )
args -> V_54 = V_10 ;
F_21 ( & V_38 -> V_39 ) ;
F_22 ( & V_2 -> V_56 ) ;
return 0 ;
}
static void
F_24 ( struct V_62 * V_62 )
{
char V_63 [ 64 ] ;
char * V_64 ;
int V_65 ;
V_64 = F_25 ( V_62 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 += 128 ) {
memcpy ( V_63 , & V_64 [ V_65 ] , 64 ) ;
memcpy ( & V_64 [ V_65 ] , & V_64 [ V_65 + 64 ] , 64 ) ;
memcpy ( & V_64 [ V_65 + 64 ] , V_63 , 64 ) ;
}
F_26 ( V_62 ) ;
}
void
F_27 ( struct V_37 * V_38 )
{
int V_67 = V_38 -> V_39 . V_30 >> V_68 ;
int V_65 ;
if ( V_38 -> V_69 == NULL )
return;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
char V_70 = F_28 ( V_38 -> V_71 [ V_65 ] ) >> 17 ;
if ( ( V_70 & 0x1 ) !=
( F_29 ( V_65 , V_38 -> V_69 ) != 0 ) ) {
F_24 ( V_38 -> V_71 [ V_65 ] ) ;
F_30 ( V_38 -> V_71 [ V_65 ] ) ;
}
}
}
void
F_31 ( struct V_37 * V_38 )
{
int V_67 = V_38 -> V_39 . V_30 >> V_68 ;
int V_65 ;
if ( V_38 -> V_69 == NULL ) {
V_38 -> V_69 = F_32 ( F_33 ( V_67 ) *
sizeof( long ) , V_72 ) ;
if ( V_38 -> V_69 == NULL ) {
F_7 ( L_4
L_5 ) ;
return;
}
}
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
if ( F_28 ( V_38 -> V_71 [ V_65 ] ) & ( 1 << 17 ) )
F_34 ( V_65 , V_38 -> V_69 ) ;
else
F_35 ( V_65 , V_38 -> V_69 ) ;
}
}
