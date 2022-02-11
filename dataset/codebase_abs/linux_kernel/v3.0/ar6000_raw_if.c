static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
struct V_5 V_6 ;
T_2 V_7 ;
struct V_8 V_9 ;
do {
F_2 ( & V_9 , sizeof( V_9 ) ) ;
V_7 = ( T_2 ) V_3 ;
V_9 . V_10 = & V_7 ;
V_9 . V_11 = sizeof( T_2 ) ;
V_9 . V_12 . V_13 = V_2 ;
V_9 . V_12 . V_14 = V_15 ;
V_9 . V_12 . V_16 = V_17 ;
V_9 . V_12 . V_18 = NULL ;
V_9 . V_12 . V_19 = NULL ;
V_9 . V_20 = V_21 ;
V_9 . V_22 = V_23 ;
F_2 ( & V_6 , sizeof( V_6 ) ) ;
V_4 = F_3 ( V_2 -> V_24 ,
& V_9 ,
& V_6 ) ;
if ( V_4 ) {
if ( V_6 . V_25 == V_26 ) {
F_4 ( V_27 , ( L_1 ) ) ;
V_4 = 0 ;
}
break;
}
F_5 ( V_2 , V_3 , V_6 . V_28 ) ;
F_4 ( V_29 , ( L_2 ,
V_3 , F_6 ( V_2 , V_3 ) ) ) ;
} while ( false );
return V_4 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_4 ;
int V_30 , V_31 , V_32 ;
T_3 * V_33 ;
T_4 V_34 ;
T_5 * V_35 = V_2 -> V_36 ;
if ( ! V_35 ) {
V_35 = V_2 -> V_36 = F_8 ( sizeof( T_5 ) ) ;
if ( V_35 ) {
F_2 ( V_35 , sizeof( T_5 ) ) ;
}
}
F_9 ( V_2 -> V_24 != NULL ) ;
if ( ! V_35 ) {
F_4 ( V_27 , ( L_3 ) ) ;
return - V_37 ;
}
V_4 = F_10 ( V_2 -> V_24 ) ;
if ( V_4 ) {
F_4 ( V_27 , ( L_4 , V_4 ) ) ;
return - V_38 ;
}
for ( V_31 = 0 ; V_31 < V_39 ; V_31 ++ ) {
V_35 -> V_40 [ V_31 ] = V_41 ;
}
for ( V_30 = V_42 ; V_30 < V_43 ; V_30 ++ ) {
F_11 ( & V_35 -> V_44 [ V_30 ] , 1 ) ;
F_11 ( & V_35 -> V_45 [ V_30 ] , 1 ) ;
F_12 ( & V_35 -> V_46 [ V_30 ] ) ;
F_12 ( & V_35 -> V_47 [ V_30 ] ) ;
V_4 = F_1 ( V_2 , V_30 ) ;
if ( V_4 ) {
break;
}
if ( F_6 ( V_2 , V_30 ) == 0 ) {
break;
}
for ( V_32 = 0 ; V_32 < V_48 ; V_32 ++ ) {
V_33 = & V_35 -> V_49 [ V_30 ] [ V_32 ] ;
memset ( V_33 , 0 , sizeof( T_3 ) ) ;
V_33 = & V_35 -> V_50 [ V_30 ] [ V_32 ] ;
memset ( V_33 , 0 , sizeof( T_3 ) ) ;
F_13 ( & V_33 -> V_51 ,
V_33 ,
V_33 -> V_52 ,
V_53 ,
F_6 ( V_2 , V_30 ) ) ;
if ( ( V_4 = F_14 ( V_2 -> V_24 , & V_33 -> V_51 ) ) != 0 )
{
F_15 () ;
return - V_54 ;
}
}
for ( V_32 = 0 ; V_32 < V_21 ; V_32 ++ ) {
V_33 = & V_35 -> V_49 [ V_30 ] [ V_32 ] ;
memset ( V_33 , 0 , sizeof( T_3 ) ) ;
}
V_35 -> V_55 [ V_30 ] = false ;
V_35 -> V_56 [ V_30 ] = true ;
}
if ( V_4 ) {
return - V_54 ;
}
F_4 ( V_57 , ( L_5 , V_30 ) ) ;
V_34 = V_23 ;
F_16 ( V_2 -> V_24 ,
V_2 ,
NULL ,
NULL ,
& V_34 ,
1 ) ;
if ( ( V_4 = F_17 ( V_2 -> V_24 ) ) != 0 ) {
F_15 () ;
return - V_54 ;
}
( V_2 ) -> V_58 = true ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
F_19 ( L_6 ) ;
F_20 ( V_2 -> V_24 ) ;
F_21 ( V_2 -> V_59 , V_2 -> V_60 , true , false ) ;
F_15 () ;
return 0 ;
}
T_3 *
F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_61 ;
T_3 * V_62 ;
T_5 * V_35 = V_2 -> V_36 ;
for ( V_61 = 0 ; V_61 < V_48 ; V_61 ++ ) {
V_62 = & V_35 -> V_50 [ V_3 ] [ V_61 ] ;
if ( V_62 -> V_63 ) {
break;
}
}
if ( V_62 -> V_63 ) {
V_35 -> V_55 [ V_3 ] = true ;
} else {
V_35 -> V_55 [ V_3 ] = false ;
}
return V_62 ;
}
T_6 F_23 ( struct V_1 * V_2 , T_1 V_3 ,
char T_7 * V_33 , T_8 V_63 )
{
int V_64 ;
T_3 * V_62 ;
T_5 * V_35 = V_2 -> V_36 ;
if ( F_6 ( V_2 , V_3 ) == 0 ) {
F_4 ( V_27 , ( L_7 , V_3 ) ) ;
return - V_65 ;
}
if ( F_24 ( & V_35 -> V_44 [ V_3 ] ) ) {
return - V_66 ;
}
V_62 = F_22 ( V_2 , V_3 ) ;
while ( ! V_35 -> V_55 [ V_3 ] ) {
F_25 ( & V_35 -> V_44 [ V_3 ] ) ;
F_4 ( V_29 , ( L_8 , V_3 ) ) ;
if ( F_26 ( V_35 -> V_46 [ V_3 ] ,
V_35 -> V_55 [ V_3 ] ) )
{
return - V_67 ;
}
if ( F_24 ( & V_35 -> V_44 [ V_3 ] ) ) {
return - V_66 ;
}
V_62 = F_22 ( V_2 , V_3 ) ;
}
V_64 = V_62 -> V_68 ;
if ( V_63 > V_62 -> V_63 - V_69 ) {
V_63 = V_62 -> V_63 - V_69 ;
}
if ( F_27 ( V_33 , & V_62 -> V_52 [ V_64 ] , V_63 ) ) {
F_25 ( & V_35 -> V_44 [ V_3 ] ) ;
return - V_65 ;
}
V_62 -> V_68 += V_63 ;
if ( V_62 -> V_68 == V_62 -> V_63 )
{
V_62 -> V_68 = 0 ;
V_62 -> V_63 = 0 ;
F_28 ( & V_62 -> V_51 ) ;
F_14 ( V_2 -> V_24 , & V_62 -> V_51 ) ;
}
V_35 -> V_55 [ V_3 ] = false ;
F_25 ( & V_35 -> V_44 [ V_3 ] ) ;
return V_63 ;
}
static T_3 *
F_29 ( struct V_1 * V_2 , T_9 V_3 )
{
int V_61 ;
T_3 * free ;
T_5 * V_35 = V_2 -> V_36 ;
free = NULL ;
for ( V_61 = 0 ; V_61 < V_21 ; V_61 ++ ) {
free = & V_35 -> V_49 [ V_3 ] [ V_61 ] ;
if ( free -> V_63 == 0 ) {
break;
}
}
if ( ! free -> V_63 ) {
V_35 -> V_56 [ V_3 ] = true ;
} else {
V_35 -> V_56 [ V_3 ] = false ;
}
return free ;
}
T_6 F_30 ( struct V_1 * V_2 , T_1 V_3 ,
char T_7 * V_33 , T_8 V_63 )
{
int V_70 ;
T_3 * free ;
T_5 * V_35 = V_2 -> V_36 ;
if ( F_6 ( V_2 , V_3 ) == 0 ) {
F_4 ( V_27 , ( L_7 , V_3 ) ) ;
return - V_65 ;
}
if ( F_24 ( & V_35 -> V_45 [ V_3 ] ) ) {
return - V_66 ;
}
free = F_29 ( V_2 , V_3 ) ;
while ( ! V_35 -> V_56 [ V_3 ] ) {
F_25 ( & V_35 -> V_45 [ V_3 ] ) ;
F_4 ( V_29 , ( L_9 , V_3 ) ) ;
if ( F_26 ( V_35 -> V_47 [ V_3 ] ,
V_35 -> V_56 [ V_3 ] ) )
{
return - V_67 ;
}
if ( F_24 ( & V_35 -> V_45 [ V_3 ] ) ) {
return - V_66 ;
}
free = F_29 ( V_2 , V_3 ) ;
}
V_70 = V_69 ;
if ( V_63 > ( V_53 - V_69 ) ) {
V_63 = V_53 - V_69 ;
}
if ( F_31 ( & free -> V_52 [ V_70 ] , V_33 , V_63 ) ) {
F_25 ( & V_35 -> V_44 [ V_3 ] ) ;
return - V_65 ;
}
free -> V_63 = V_63 ;
F_32 ( & free -> V_51 ,
free ,
& free -> V_52 [ V_70 ] ,
V_63 ,
F_6 ( V_2 , V_3 ) ,
V_71 ) ;
F_33 ( V_2 -> V_24 , & free -> V_51 ) ;
V_35 -> V_56 [ V_3 ] = false ;
F_25 ( & V_35 -> V_45 [ V_3 ] ) ;
return V_63 ;
}
