static T_1 F_1 ( const T_2 V_1 ) {
static T_1 V_2 [] = L_1 ;
if ( V_1 >= ( T_2 ) sizeof( V_2 ) )
return '?' ;
return V_2 [ V_1 ] ;
}
static T_3 F_2 ( T_4 V_3 , int * V_4 , T_1 * * V_5 )
{
T_5 V_6 ;
T_5 V_7 ;
T_5 V_8 ;
T_5 V_9 ;
T_3 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_2 * V_15 ;
T_5 V_16 ;
T_2 * V_17 ;
T_2 * V_18 ;
T_2 * V_19 ;
T_5 V_20 ;
if ( ! F_3 ( V_3 , & V_16 , 2 , V_4 , V_5 ) ) {
if ( * V_4 == 0 ) {
return - 2 ;
}
if ( * V_4 != V_21 )
return - 1 ;
return 0 ;
}
V_6 = F_4 ( & V_16 ) ;
if ( V_6 < 3 )
return 0 ;
if ( V_6 > V_22 )
return 0 ;
if ( ! F_5 ( V_3 , & V_16 , 2 , V_4 , V_5 ) ) {
if ( * V_4 != V_21 )
return - 1 ;
return 0 ;
}
V_7 = F_4 ( & V_16 ) ;
V_8 = 4 ;
V_15 = ( T_2 * ) F_6 ( sizeof( * V_14 ) + V_6 ) ;
V_14 = (struct V_13 * ) ( void * ) V_15 ;
V_12 = (struct V_11 * ) ( void * ) V_15 ;
for ( V_10 = 1 ; V_10 <= 2 ; ++ V_10 ) {
if ( V_10 == 1 ) {
V_17 = ( T_2 * ) ( V_12 + 1 ) ;
V_9 = sizeof( * V_12 ) + V_6 ;
} else if ( V_10 == 2 ) {
V_17 = ( T_2 * ) ( V_14 + 1 ) ;
V_9 = sizeof( * V_14 ) + V_6 ;
if ( V_7 != sizeof( * V_14 ) )
continue;
} else {
continue;
}
if ( ! F_5 ( V_3 , V_15 + V_8 , V_9 - V_8 , V_4 , V_5 ) ) {
F_7 ( V_15 ) ;
if ( * V_4 != V_21 )
return - 1 ;
return 0 ;
}
V_8 += V_9 - V_8 ;
if ( F_1 ( V_17 [ 0 ] ) == '?' )
continue;
V_18 = ( T_2 * ) memchr ( V_17 , '\0' , V_6 - 1 ) ;
if ( V_18 == NULL )
continue;
++ V_18 ;
V_20 = ( T_5 ) ( V_6 - ( V_18 - V_17 ) ) ;
V_19 = ( T_2 * ) memchr ( V_18 , '\0' , V_20 ) ;
if ( V_19 && ( V_17 + V_6 - 1 != V_19 ) )
continue;
F_7 ( V_15 ) ;
return V_10 ;
}
F_7 ( V_15 ) ;
return 0 ;
}
T_3 F_8 ( const T_2 * V_23 ) {
const T_5 * V_24 ;
const T_5 * V_25 ;
T_3 V_26 = 0 ;
V_24 = ( const T_5 * ) ( const void * ) V_23 ;
while( F_9 ( * V_24 ) ) {
V_25 = ( const T_5 * ) ( const void * ) ( V_23 + 2 ) ;
V_26 += 2 + 2 + F_9 ( * V_25 ) ;
V_23 += 2 + 2 + F_9 ( * V_25 ) ;
V_24 = ( const T_5 * ) ( const void * ) V_23 ;
}
V_26 += 2 + 2 ;
return V_26 ;
}
static T_6 F_10 ( struct V_27 * V_28 , T_4 V_3 ,
struct V_29 * V_30 , T_7 * V_31 , int * V_4 , T_1 * * V_5 )
{
T_3 V_32 ;
T_5 V_6 ;
T_8 V_16 [ 2 ] ;
T_2 * V_23 ;
struct V_11 * V_12 ;
if ( ! F_3 ( V_3 , & V_16 , 2 , V_4 , V_5 ) ) {
return FALSE ;
}
V_6 = F_4 ( V_16 ) ;
if ( V_28 -> V_10 == 1 ) {
V_32 = ( T_3 ) sizeof( struct V_11 ) + V_6 ;
} else if ( V_28 -> V_10 == 2 ) {
V_32 = ( T_3 ) sizeof( struct V_13 ) + V_6 ;
} else {
return FALSE ;
}
F_11 ( V_31 , V_32 ) ;
V_23 = F_12 ( V_31 ) ;
V_12 = (struct V_11 * ) ( void * ) V_23 ;
memcpy ( V_23 , V_16 , 2 ) ;
if ( ! F_5 ( V_3 , V_23 + 2 , V_32 - 2 , V_4 , V_5 ) ) {
return FALSE ;
}
V_30 -> V_33 = V_34 ;
V_30 -> V_35 = V_36 ;
V_30 -> V_37 . V_38 = ( V_39 ) F_13 ( V_12 -> V_40 ) ;
V_30 -> V_37 . V_41 = F_13 ( V_12 -> V_42 ) ;
V_30 -> V_43 = V_32 ;
V_30 -> V_44 = V_32 ;
V_30 -> V_45 . V_28 . V_10 = V_28 -> V_10 ;
return TRUE ;
}
static T_6 F_14 ( T_9 * V_46 , int * V_4 , T_1 * * V_5 ,
T_10 * V_47 )
{
* V_47 = F_15 ( V_46 -> V_3 ) ;
return F_10 ( (struct V_27 * ) V_46 -> V_48 , V_46 -> V_3 ,
& V_46 -> V_30 , V_46 -> V_49 , V_4 , V_5 ) ;
}
static T_6 F_16 ( T_9 * V_46 , T_10 V_50 ,
struct V_29 * V_30 , T_7 * V_31 ,
int * V_4 , T_1 * * V_5 )
{
if ( F_17 ( V_46 -> V_51 , V_50 , V_52 , V_4 ) == - 1 )
return FALSE ;
if ( ! F_10 ( (struct V_27 * ) V_46 -> V_48 , V_46 -> V_51 ,
V_30 , V_31 , V_4 , V_5 ) ) {
if ( * V_4 == 0 )
* V_4 = V_21 ;
return FALSE ;
}
return TRUE ;
}
T_11 F_18 ( T_9 * V_46 , int * V_4 , T_1 * * V_5 )
{
T_3 V_10 ;
T_3 V_53 ;
struct V_27 * V_28 ;
V_10 = F_2 ( V_46 -> V_3 , V_4 , V_5 ) ;
if ( V_10 == - 1 )
return V_54 ;
if ( V_10 == 0 )
return V_55 ;
if ( V_10 == - 2 )
return V_55 ;
V_53 = F_2 ( V_46 -> V_3 , V_4 , V_5 ) ;
if ( V_53 == - 1 )
return V_54 ;
if ( V_53 == 0 )
return V_55 ;
if ( V_53 != - 2 ) {
if ( V_53 != V_10 ) {
return V_55 ;
}
V_53 = F_2 ( V_46 -> V_3 , V_4 , V_5 ) ;
if ( V_53 < 0 )
return V_54 ;
if ( V_53 == 0 )
return V_55 ;
if ( V_53 != - 2 ) {
if ( V_53 != V_10 ) {
return V_55 ;
}
}
}
if ( F_17 ( V_46 -> V_3 , 0 , V_52 , V_4 ) == - 1 )
return V_54 ;
V_28 = (struct V_27 * ) F_6 ( sizeof( struct V_27 ) ) ;
V_28 -> V_10 = V_10 ;
V_46 -> V_48 = V_28 ;
V_46 -> V_56 = V_57 ;
V_46 -> V_58 = V_59 ;
V_46 -> V_60 = 0 ;
V_46 -> V_61 = F_14 ;
V_46 -> V_62 = F_16 ;
V_46 -> V_63 = V_64 ;
return V_65 ;
}
int F_19 ( int V_66 )
{
if ( V_66 == V_67 )
return V_68 ;
if ( V_66 != V_59 && V_66 != V_69 )
return V_70 ;
return 0 ;
}
static T_6 F_20 ( T_12 * V_71 ,
const struct V_29 * V_30 ,
const T_2 * V_23 , int * V_4 , T_1 * * V_5 V_72 )
{
int V_43 ;
if ( V_30 -> V_33 != V_34 ) {
* V_4 = V_73 ;
return FALSE ;
}
V_43 = V_30 -> V_43 ;
if ( V_71 -> V_66 == V_69 ) {
T_3 V_74 ;
V_74 = F_8 ( V_23 ) ;
V_23 += V_74 ;
V_43 -= V_74 ;
}
if ( ! F_21 ( V_71 , V_23 , V_43 , V_4 ) )
return FALSE ;
V_71 -> V_75 += V_43 ;
return TRUE ;
}
T_6 F_22 ( T_12 * V_71 , int * V_4 V_72 )
{
V_71 -> V_76 = F_20 ;
return TRUE ;
}
