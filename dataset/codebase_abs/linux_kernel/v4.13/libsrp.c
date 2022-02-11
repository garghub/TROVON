static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_2 -> V_9 = F_2 ( V_3 , sizeof( struct V_6 * ) , V_10 ) ;
if ( ! V_2 -> V_9 )
return - V_11 ;
V_2 -> V_12 = F_2 ( V_3 , sizeof( struct V_6 ) , V_10 ) ;
if ( ! V_2 -> V_12 )
goto V_13;
F_3 ( & V_2 -> V_14 ) ;
F_4 ( & V_2 -> V_15 , ( void * ) V_2 -> V_9 , V_3 * sizeof( void * ) ) ;
for ( V_8 = 0 , V_7 = V_2 -> V_12 ; V_8 < V_3 ; V_8 ++ ) {
F_5 ( & V_2 -> V_15 , ( void * ) & V_7 , sizeof( void * ) ) ;
V_7 -> V_16 = V_5 [ V_8 ] ;
V_7 ++ ;
}
return 0 ;
V_13:
F_6 ( V_2 -> V_9 ) ;
return - V_11 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_12 ) ;
F_6 ( V_2 -> V_9 ) ;
}
static struct V_4 * * F_8 ( struct V_17 * V_18 ,
T_1 V_3 , T_1 V_19 )
{
struct V_4 * * V_5 ;
int V_8 ;
V_5 = F_2 ( V_3 , sizeof( struct V_4 * ) , V_10 ) ;
if ( ! V_5 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_3 ; V_8 ++ ) {
V_5 [ V_8 ] = F_9 ( sizeof( * V_5 [ V_8 ] ) , V_10 ) ;
if ( ! V_5 [ V_8 ] )
goto V_20;
V_5 [ V_8 ] -> V_21 = F_10 ( V_18 , V_19 , & V_5 [ V_8 ] -> V_22 ,
V_10 ) ;
if ( ! V_5 [ V_8 ] -> V_21 )
goto V_20;
}
return V_5 ;
V_20:
for ( V_8 = 0 ; V_8 < V_3 && V_5 [ V_8 ] ; V_8 ++ ) {
if ( V_5 [ V_8 ] -> V_21 ) {
F_11 ( V_18 , V_19 , V_5 [ V_8 ] -> V_21 ,
V_5 [ V_8 ] -> V_22 ) ;
}
F_6 ( V_5 [ V_8 ] ) ;
}
F_6 ( V_5 ) ;
return NULL ;
}
static void F_12 ( struct V_17 * V_18 , struct V_4 * * V_5 ,
T_1 V_3 , T_1 V_19 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 ; V_8 ++ ) {
F_11 ( V_18 , V_19 , V_5 [ V_8 ] -> V_21 , V_5 [ V_8 ] -> V_22 ) ;
F_6 ( V_5 [ V_8 ] ) ;
}
F_6 ( V_5 ) ;
}
int F_13 ( struct V_23 * V_24 , struct V_17 * V_18 ,
T_1 V_25 , T_1 V_26 )
{
int V_27 ;
F_3 ( & V_24 -> V_14 ) ;
V_24 -> V_18 = V_18 ;
V_24 -> V_28 = V_26 ;
V_24 -> V_29 = V_25 ;
V_24 -> V_30 = F_8 ( V_24 -> V_18 , V_25 , V_26 ) ;
if ( ! V_24 -> V_30 )
return - V_11 ;
V_27 = F_1 ( & V_24 -> V_31 , V_25 , V_24 -> V_30 ) ;
if ( V_27 )
goto V_32;
F_14 ( V_24 -> V_18 , V_24 ) ;
return 0 ;
V_32:
F_12 ( V_24 -> V_18 , V_24 -> V_30 , V_25 , V_26 ) ;
return - V_11 ;
}
void F_15 ( struct V_23 * V_24 )
{
F_14 ( V_24 -> V_18 , NULL ) ;
F_12 ( V_24 -> V_18 , V_24 -> V_30 , V_24 -> V_29 ,
V_24 -> V_28 ) ;
F_7 ( & V_24 -> V_31 ) ;
}
struct V_6 * F_16 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = NULL ;
if ( F_17 ( & V_24 -> V_31 . V_15 , ( void * ) & V_7 ,
sizeof( void * ) ,
& V_24 -> V_31 . V_14 ) != sizeof( void * ) ) {
F_18 ( 1 , L_1 ) ;
return NULL ;
}
if ( ! V_7 )
return V_7 ;
V_7 -> V_24 = V_24 ;
V_7 -> V_33 = 0 ;
return V_7 ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 ( & V_7 -> V_24 -> V_31 . V_15 , ( void * ) & V_7 ,
sizeof( void * ) , & V_7 -> V_24 -> V_31 . V_14 ) ;
}
static int F_21 ( struct V_34 * V_35 , struct V_36 * V_37 ,
enum V_38 V_39 , T_2 V_40 ,
int V_41 , int V_42 )
{
struct V_6 * V_7 = NULL ;
struct V_43 * V_44 = NULL ;
int V_27 , V_45 = 0 , V_46 ;
if ( V_41 ) {
V_7 = V_35 -> V_7 ;
V_44 = V_35 -> V_47 . V_48 ;
V_45 = F_22 ( V_7 -> V_24 -> V_18 , V_44 , V_35 -> V_47 . V_49 ,
V_50 ) ;
if ( ! V_45 ) {
F_23 ( L_2 , V_7 ,
V_35 -> V_47 . V_49 ) ;
return 0 ;
}
V_46 = F_24 ( V_35 -> V_47 . V_51 , F_25 ( V_37 -> V_46 ) ) ;
} else {
V_46 = F_25 ( V_37 -> V_46 ) ;
}
V_27 = V_40 ( V_35 , V_44 , V_45 , V_37 , 1 , V_39 , V_46 ) ;
if ( V_41 )
F_26 ( V_7 -> V_24 -> V_18 , V_44 , V_45 , V_50 ) ;
return V_27 ;
}
static int F_27 ( struct V_34 * V_35 , struct V_52 * V_52 ,
struct V_53 * V_54 ,
enum V_38 V_39 , T_2 V_40 ,
int V_41 , int V_42 )
{
struct V_6 * V_7 = NULL ;
struct V_36 * V_37 = NULL ;
struct V_43 V_55 , * V_44 = NULL ;
T_3 V_56 = 0 ;
int V_27 = 0 ;
int V_57 , V_45 = 0 , V_46 ;
if ( V_41 || V_42 ) {
V_7 = V_35 -> V_7 ;
V_44 = V_35 -> V_47 . V_48 ;
}
V_57 = F_25 ( V_54 -> V_58 . V_46 ) / sizeof( struct V_36 ) ;
if ( ( V_39 == V_59 && V_57 == V_52 -> V_60 ) ||
( V_39 == V_61 && V_57 == V_52 -> V_62 ) ) {
V_37 = & V_54 -> V_63 [ 0 ] ;
goto V_64;
}
if ( V_42 && V_41 ) {
V_37 = F_10 ( V_7 -> V_24 -> V_18 ,
F_25 ( V_54 -> V_58 . V_46 ) ,
& V_56 , V_10 ) ;
if ( ! V_37 ) {
F_23 ( L_3 ,
F_25 ( V_54 -> V_58 . V_46 ) ) ;
return - V_11 ;
}
F_28 ( & V_55 , V_37 , F_25 ( V_54 -> V_58 . V_46 ) ) ;
F_29 ( & V_55 ) = V_56 ;
F_30 ( & V_55 ) = F_25 ( V_54 -> V_58 . V_46 ) ;
V_27 = V_40 ( V_35 , & V_55 , 1 , & V_54 -> V_58 , 1 , V_61 ,
F_25 ( V_54 -> V_58 . V_46 ) ) ;
if ( V_27 ) {
F_23 ( L_4 , V_27 ) ;
goto V_65;
}
} else {
F_23 ( L_5 ) ;
return - V_66 ;
}
V_64:
if ( V_41 ) {
V_45 = F_22 ( V_7 -> V_24 -> V_18 , V_44 , V_35 -> V_47 . V_49 ,
V_50 ) ;
if ( ! V_45 ) {
F_23 ( L_2 , V_7 ,
V_35 -> V_47 . V_49 ) ;
V_27 = - V_67 ;
goto V_65;
}
V_46 = F_24 ( V_35 -> V_47 . V_51 , F_25 ( V_54 -> V_46 ) ) ;
} else {
V_46 = F_25 ( V_54 -> V_46 ) ;
}
V_27 = V_40 ( V_35 , V_44 , V_45 , V_37 , V_57 , V_39 , V_46 ) ;
if ( V_41 )
F_26 ( V_7 -> V_24 -> V_18 , V_44 , V_45 , V_50 ) ;
V_65:
if ( V_56 && V_41 ) {
F_11 ( V_7 -> V_24 -> V_18 ,
F_25 ( V_54 -> V_58 . V_46 ) , V_37 , V_56 ) ;
}
return V_27 ;
}
static int F_31 ( struct V_52 * V_35 )
{
int V_19 = 0 ;
T_4 V_68 = V_35 -> V_69 >> 4 ;
switch ( V_68 ) {
case V_70 :
break;
case V_71 :
V_19 = sizeof( struct V_36 ) ;
break;
case V_72 :
V_19 = sizeof( struct V_53 ) +
sizeof( struct V_36 ) * V_35 -> V_62 ;
break;
default:
F_23 ( L_6 , V_68 ) ;
break;
}
return V_19 ;
}
int F_32 ( struct V_34 * V_35 , struct V_52 * V_52 ,
T_2 V_40 , int V_41 , int V_42 )
{
struct V_36 * V_37 ;
struct V_53 * V_54 ;
enum V_38 V_39 ;
int V_73 , V_27 = 0 ;
T_4 V_74 ;
if ( ! V_35 -> V_47 . V_49 )
return 0 ;
V_73 = V_52 -> V_75 & ~ 3 ;
V_39 = F_33 ( V_52 ) ;
if ( V_39 == V_59 )
V_73 += F_31 ( V_52 ) ;
if ( V_39 == V_61 )
V_74 = V_52 -> V_69 >> 4 ;
else
V_74 = V_52 -> V_69 & ( ( 1U << 4 ) - 1 ) ;
switch ( V_74 ) {
case V_70 :
break;
case V_71 :
V_37 = (struct V_36 * ) ( V_52 -> V_76 + V_73 ) ;
V_27 = F_21 ( V_35 , V_37 , V_39 , V_40 , V_41 , V_42 ) ;
break;
case V_72 :
V_54 = (struct V_53 * ) ( V_52 -> V_76 + V_73 ) ;
V_27 = F_27 ( V_35 , V_52 , V_54 , V_39 , V_40 , V_41 ,
V_42 ) ;
break;
default:
F_23 ( L_7 , V_39 , V_74 ) ;
V_27 = - V_66 ;
}
return V_27 ;
}
T_5 F_34 ( struct V_52 * V_35 , enum V_38 V_39 )
{
struct V_36 * V_37 ;
struct V_53 * V_54 ;
T_5 V_46 = 0 ;
T_6 V_73 = V_35 -> V_75 & ~ 3 ;
T_4 V_68 ;
if ( V_39 == V_61 ) {
V_68 = V_35 -> V_69 >> 4 ;
} else {
V_68 = V_35 -> V_69 & ( ( 1U << 4 ) - 1 ) ;
V_73 += F_31 ( V_35 ) ;
}
switch ( V_68 ) {
case V_70 :
break;
case V_71 :
V_37 = (struct V_36 * ) ( V_35 -> V_76 + V_73 ) ;
V_46 = F_25 ( V_37 -> V_46 ) ;
break;
case V_72 :
V_54 = (struct V_53 * ) ( V_35 -> V_76 + V_73 ) ;
V_46 = F_25 ( V_54 -> V_46 ) ;
break;
default:
F_23 ( L_8 , V_68 ) ;
break;
}
return V_46 ;
}
int F_35 ( struct V_52 * V_52 , enum V_38 * V_39 ,
T_5 * V_77 )
{
struct V_53 * V_78 ;
struct V_36 * V_79 ;
T_6 V_80 ;
int V_81 ;
F_36 ( ! F_37 ( V_52 -> V_76 [ 0 ] , ( V_82 ) 0 )
&& ! F_37 ( V_52 -> V_76 [ 0 ] , ( T_4 ) 0 ) ) ;
F_38 ( ! V_39 ) ;
F_38 ( ! V_77 ) ;
V_81 = 0 ;
* V_77 = 0 ;
* V_39 = V_83 ;
if ( V_52 -> V_69 & 0xf )
* V_39 = V_59 ;
else if ( V_52 -> V_69 >> 4 )
* V_39 = V_61 ;
V_80 = V_52 -> V_75 & ~ 3 ;
if ( ( ( V_52 -> V_69 & 0xf ) == V_71 ) ||
( ( V_52 -> V_69 >> 4 ) == V_71 ) ) {
V_79 = (struct V_36 * ) ( V_52 -> V_76
+ V_80 ) ;
* V_77 = F_25 ( V_79 -> V_46 ) ;
} else if ( ( ( V_52 -> V_69 & 0xf ) == V_72 ) ||
( ( V_52 -> V_69 >> 4 ) == V_72 ) ) {
V_78 = (struct V_53 * ) ( V_52 -> V_76
+ V_80 ) ;
* V_77 = F_25 ( V_78 -> V_46 ) ;
}
return V_81 ;
}
