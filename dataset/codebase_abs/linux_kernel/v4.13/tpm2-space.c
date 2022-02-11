static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ ) {
if ( V_4 -> V_6 [ V_5 ] )
F_3 ( V_2 , V_4 -> V_6 [ V_5 ] ,
V_7 ) ;
}
}
int F_4 ( struct V_3 * V_4 )
{
V_4 -> V_8 = F_5 ( V_9 , V_10 ) ;
if ( ! V_4 -> V_8 )
return - V_11 ;
V_4 -> V_12 = F_5 ( V_9 , V_10 ) ;
if ( V_4 -> V_12 == NULL ) {
F_6 ( V_4 -> V_8 ) ;
return - V_11 ;
}
return 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_8 ( & V_2 -> V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_13 ) ;
F_6 ( V_4 -> V_8 ) ;
F_6 ( V_4 -> V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_14 ,
unsigned int * V_15 , T_2 * V_16 )
{
struct V_17 V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
int V_22 ;
V_22 = F_11 ( & V_18 , V_23 , V_24 ) ;
if ( V_22 )
return V_22 ;
V_20 = (struct V_19 * ) & V_14 [ * V_15 ] ;
V_21 = sizeof( * V_20 ) + F_12 ( V_20 -> V_25 ) ;
F_13 ( & V_18 , & V_14 [ * V_15 ] , V_21 ) ;
V_22 = F_14 ( V_2 , NULL , V_18 . V_26 , V_9 , 4 ,
V_7 , NULL ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_27 , L_1 ,
V_28 , V_22 ) ;
F_16 ( & V_18 ) ;
return - V_29 ;
} else if ( F_17 ( V_22 ) == V_30 ||
V_22 == V_31 ) {
V_22 = - V_32 ;
F_16 ( & V_18 ) ;
} else if ( V_22 > 0 ) {
F_15 ( & V_2 -> V_27 , L_2 ,
V_28 , V_22 ) ;
F_16 ( & V_18 ) ;
return - V_29 ;
}
* V_16 = F_18 ( ( V_33 * ) & V_18 . V_26 [ V_34 ] ) ;
* V_15 += V_21 ;
F_16 ( & V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_14 ,
unsigned int V_35 , unsigned int * V_15 )
{
struct V_17 V_18 ;
unsigned int V_21 ;
int V_22 ;
V_22 = F_11 ( & V_18 , V_23 , V_36 ) ;
if ( V_22 )
return V_22 ;
F_20 ( & V_18 , V_16 ) ;
V_22 = F_14 ( V_2 , NULL , V_18 . V_26 , V_9 , 0 ,
V_7 , NULL ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_27 , L_1 ,
V_28 , V_22 ) ;
F_16 ( & V_18 ) ;
return - V_29 ;
} else if ( F_17 ( V_22 ) == V_31 ) {
F_16 ( & V_18 ) ;
return - V_32 ;
} else if ( V_22 ) {
F_15 ( & V_2 -> V_27 , L_2 ,
V_28 , V_22 ) ;
F_16 ( & V_18 ) ;
return - V_29 ;
}
V_21 = F_21 ( & V_18 ) - V_34 ;
if ( ( * V_15 + V_21 ) > V_35 ) {
F_15 ( & V_2 -> V_27 , L_3 , V_28 ) ;
F_16 ( & V_18 ) ;
return - V_11 ;
}
memcpy ( & V_14 [ * V_15 ] , & V_18 . V_26 [ V_34 ] , V_21 ) ;
* V_15 += V_21 ;
F_16 ( & V_18 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_38 ) ; V_5 ++ )
if ( V_4 -> V_38 [ V_5 ] && ~ V_4 -> V_38 [ V_5 ] )
F_3 ( V_2 , V_4 -> V_38 [ V_5 ] ,
V_7 ) ;
F_1 ( V_2 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
unsigned int V_15 ;
int V_5 ;
int V_22 ;
for ( V_5 = 0 , V_15 = 0 ; V_5 < F_2 ( V_4 -> V_38 ) ; V_5 ++ ) {
if ( ! V_4 -> V_38 [ V_5 ] )
continue;
if ( ~ V_4 -> V_38 [ V_5 ] ) {
F_24 ( & V_2 -> V_27 , L_4 ) ;
return - V_29 ;
}
V_22 = F_10 ( V_2 , V_4 -> V_8 , & V_15 ,
& V_4 -> V_38 [ V_5 ] ) ;
if ( V_22 )
return V_22 ;
}
for ( V_5 = 0 , V_15 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ ) {
T_2 V_16 ;
if ( ! V_4 -> V_6 [ V_5 ] )
continue;
V_22 = F_10 ( V_2 , V_4 -> V_12 ,
& V_15 , & V_16 ) ;
if ( V_22 == - V_32 ) {
V_4 -> V_6 [ V_5 ] = 0 ;
} else if ( V_22 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
if ( V_16 != V_4 -> V_6 [ V_5 ] ) {
F_15 ( & V_2 -> V_27 , L_5 ) ;
F_22 ( V_2 ) ;
return - V_29 ;
}
}
return 0 ;
}
static bool F_25 ( struct V_3 * V_4 , void * V_16 )
{
T_2 V_39 = F_18 ( ( V_33 * ) V_16 ) ;
T_2 V_40 ;
int V_5 ;
V_5 = 0xFFFFFF - ( V_39 & 0xFFFFFF ) ;
if ( V_5 >= F_2 ( V_4 -> V_38 ) || ! V_4 -> V_38 [ V_5 ] )
return false ;
V_40 = V_4 -> V_38 [ V_5 ] ;
* ( ( V_33 * ) V_16 ) = F_26 ( V_40 ) ;
return true ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_41 , T_1 * V_42 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
unsigned int V_43 ;
T_2 V_44 ;
T_2 * V_16 ;
int V_5 ;
V_5 = F_28 ( V_2 , V_41 ) ;
if ( V_5 < 0 )
return - V_45 ;
V_44 = V_2 -> V_46 [ V_5 ] ;
V_43 = ( V_44 >> V_47 ) & F_29 ( 2 , 0 ) ;
V_16 = ( T_2 * ) & V_42 [ V_34 ] ;
for ( V_5 = 0 ; V_5 < V_43 ; V_5 ++ , V_16 ++ ) {
if ( ( F_30 ( * V_16 ) & 0xFF000000 ) == V_48 ) {
if ( ! F_25 ( V_4 , V_16 ) )
return - V_45 ;
}
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_41 ,
T_1 * V_42 )
{
int V_22 ;
if ( ! V_4 )
return 0 ;
memcpy ( & V_2 -> V_37 . V_38 , & V_4 -> V_38 ,
sizeof( V_4 -> V_38 ) ) ;
memcpy ( & V_2 -> V_37 . V_6 , & V_4 -> V_6 ,
sizeof( V_4 -> V_6 ) ) ;
memcpy ( V_2 -> V_37 . V_8 , V_4 -> V_8 , V_9 ) ;
memcpy ( V_2 -> V_37 . V_12 , V_4 -> V_12 , V_9 ) ;
V_22 = F_23 ( V_2 ) ;
if ( V_22 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
V_22 = F_27 ( V_2 , V_41 , V_42 ) ;
if ( V_22 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ )
if ( V_4 -> V_6 [ V_5 ] == 0 )
break;
if ( V_5 == F_2 ( V_4 -> V_6 ) )
return false ;
V_4 -> V_6 [ V_5 ] = V_16 ;
return true ;
}
static T_2 F_33 ( struct V_3 * V_4 , T_2 V_40 , bool V_49 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_38 ) ; V_5 ++ ) {
if ( V_49 ) {
if ( ! V_4 -> V_38 [ V_5 ] ) {
V_4 -> V_38 [ V_5 ] = V_40 ;
break;
}
} else if ( V_4 -> V_38 [ V_5 ] == V_40 )
break;
}
if ( V_5 == F_2 ( V_4 -> V_38 ) )
return 0 ;
return V_48 | ( 0xFFFFFF - V_5 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_41 , T_1 * V_50 ,
T_3 V_51 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
struct V_52 * V_53 = ( void * ) V_50 ;
T_2 V_40 ;
T_2 V_54 ;
T_2 V_39 ;
T_2 V_44 ;
int V_5 ;
if ( F_30 ( V_53 -> V_55 ) != V_56 )
return 0 ;
V_5 = F_28 ( V_2 , V_41 ) ;
if ( V_5 < 0 )
return - V_29 ;
V_44 = V_2 -> V_46 [ V_5 ] ;
if ( ! ( ( V_44 >> V_57 ) & 1 ) )
return 0 ;
V_40 = F_18 ( ( V_33 * ) & V_50 [ V_34 ] ) ;
V_54 = V_40 & 0xFF000000 ;
switch ( V_54 ) {
case V_48 :
V_39 = F_33 ( V_4 , V_40 , true ) ;
if ( ! V_39 )
goto V_58;
* ( V_33 * ) & V_50 [ V_34 ] = F_26 ( V_39 ) ;
break;
case V_59 :
case V_60 :
if ( ! F_32 ( V_2 , V_40 ) )
goto V_58;
break;
default:
F_24 ( & V_2 -> V_27 , L_6 ,
V_28 , V_40 ) ;
break;
} ;
return 0 ;
V_58:
F_3 ( V_2 , V_40 , V_7 ) ;
F_15 ( & V_2 -> V_27 , L_7 , V_28 ,
V_40 ) ;
return - V_11 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 V_41 , T_1 * V_50 ,
T_3 V_51 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
struct V_52 * V_53 = ( void * ) V_50 ;
struct V_61 * V_26 ;
T_2 V_40 ;
T_2 V_54 ;
T_2 V_39 ;
int V_5 ;
int V_62 ;
if ( V_41 != V_63 ||
F_30 ( V_53 -> V_55 ) != V_56 ) {
return 0 ;
}
if ( V_51 < V_34 + 9 )
return - V_29 ;
V_26 = ( void * ) & V_50 [ V_34 ] ;
if ( F_30 ( V_26 -> V_64 ) != V_65 )
return 0 ;
if ( V_51 != V_34 + 9 + 4 * F_30 ( V_26 -> V_66 ) )
return - V_29 ;
for ( V_5 = 0 , V_62 = 0 ; V_5 < F_30 ( V_26 -> V_66 ) ; V_5 ++ ) {
V_40 = F_18 ( ( V_33 * ) & V_26 -> V_67 [ V_5 ] ) ;
V_54 = V_40 & 0xFF000000 ;
switch ( V_54 ) {
case V_48 :
V_39 = F_33 ( V_4 , V_40 , false ) ;
if ( ! V_39 )
break;
V_26 -> V_67 [ V_62 ] = F_26 ( V_39 ) ;
V_62 ++ ;
break;
default:
V_26 -> V_67 [ V_62 ] = F_26 ( V_40 ) ;
V_62 ++ ;
break;
}
}
V_53 -> V_68 = F_26 ( V_34 + 9 + 4 * V_62 ) ;
V_26 -> V_66 = F_26 ( V_62 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_37 ;
unsigned int V_15 ;
int V_5 ;
int V_22 ;
for ( V_5 = 0 , V_15 = 0 ; V_5 < F_2 ( V_4 -> V_38 ) ; V_5 ++ ) {
if ( ! ( V_4 -> V_38 [ V_5 ] && ~ V_4 -> V_38 [ V_5 ] ) )
continue;
V_22 = F_19 ( V_2 , V_4 -> V_38 [ V_5 ] ,
V_4 -> V_8 , V_9 ,
& V_15 ) ;
if ( V_22 == - V_32 ) {
V_4 -> V_38 [ V_5 ] = 0 ;
continue;
} else if ( V_22 )
return V_22 ;
F_3 ( V_2 , V_4 -> V_38 [ V_5 ] ,
V_7 ) ;
V_4 -> V_38 [ V_5 ] = ~ 0 ;
}
for ( V_5 = 0 , V_15 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ ) {
if ( ! V_4 -> V_6 [ V_5 ] )
continue;
V_22 = F_19 ( V_2 , V_4 -> V_6 [ V_5 ] ,
V_4 -> V_12 , V_9 ,
& V_15 ) ;
if ( V_22 == - V_32 ) {
V_4 -> V_6 [ V_5 ] = 0 ;
} else if ( V_22 < 0 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_41 , T_1 * V_14 , T_3 * V_69 )
{
struct V_52 * V_53 = ( void * ) V_14 ;
int V_22 ;
if ( ! V_4 )
return 0 ;
V_22 = F_34 ( V_2 , V_41 , V_14 , * V_69 ) ;
if ( V_22 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
V_22 = F_35 ( V_2 , V_41 , V_14 , * V_69 ) ;
if ( V_22 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
V_22 = F_36 ( V_2 ) ;
if ( V_22 ) {
F_22 ( V_2 ) ;
return V_22 ;
}
* V_69 = F_30 ( V_53 -> V_68 ) ;
memcpy ( & V_4 -> V_38 , & V_2 -> V_37 . V_38 ,
sizeof( V_4 -> V_38 ) ) ;
memcpy ( & V_4 -> V_6 , & V_2 -> V_37 . V_6 ,
sizeof( V_4 -> V_6 ) ) ;
memcpy ( V_4 -> V_8 , V_2 -> V_37 . V_8 , V_9 ) ;
memcpy ( V_4 -> V_12 , V_2 -> V_37 . V_12 , V_9 ) ;
return 0 ;
}
