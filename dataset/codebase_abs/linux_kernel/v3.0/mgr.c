int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
F_3 ( V_2 != NULL ) ;
F_3 ( V_10 > 0 ) ;
V_6 = F_4 ( sizeof( struct V_1 ) , V_11 ) ;
if ( V_6 ) {
V_5 = F_5 ( V_12 , & V_6 -> V_13 ) ;
if ( ! V_5 ) {
if ( V_8 ) {
V_8 -> V_1 = ( void * ) V_6 ;
} else {
V_5 = - V_14 ;
F_6 ( L_1 ,
V_15 ) ;
}
if ( ! V_5 ) {
* V_2 = V_6 ;
} else {
F_7 ( V_6 -> V_13 ) ;
F_8 ( V_6 ) ;
}
} else {
F_8 ( V_6 ) ;
}
} else {
V_5 = - V_16 ;
}
F_9 ( V_5 || V_6 ) ;
return V_5 ;
}
int F_10 ( struct V_1 * V_17 )
{
int V_5 = 0 ;
struct V_1 * V_6 = (struct V_1 * ) V_17 ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
F_3 ( V_10 > 0 ) ;
F_3 ( V_17 ) ;
if ( V_17 -> V_13 )
F_7 ( V_17 -> V_13 ) ;
F_8 ( V_6 ) ;
if ( V_8 ) {
V_8 -> V_1 = NULL ;
} else {
V_5 = - V_14 ;
F_6 ( L_1 , V_15 ) ;
}
return V_5 ;
}
int F_11 ( T_1 V_18 , struct V_19 * V_20 ,
T_1 V_21 , T_1 * V_22 )
{
int V_5 = 0 ;
struct V_23 V_24 ;
T_1 V_25 = 0 ;
struct V_26 V_27 ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
F_3 ( V_20 != NULL ) ;
F_3 ( V_22 != NULL ) ;
F_3 ( V_21 >= sizeof( struct V_19 ) ) ;
F_3 ( V_10 > 0 ) ;
* V_22 = 0 ;
if ( ! V_8 || ! V_8 -> V_1 ) {
F_6 ( L_2 , V_15 ) ;
return - V_28 ;
}
V_6 = V_8 -> V_1 ;
F_12 ( V_6 ) ;
while ( ! V_5 ) {
V_5 = F_13 ( V_25 ++ , V_29 ,
& V_24 ) ;
if ( V_5 )
break;
* V_22 = V_25 ;
if ( V_18 == ( V_25 - 1 ) ) {
V_5 = F_14 ( V_6 -> V_13 ,
& V_24 , V_29 , & V_27 ) ;
if ( V_5 )
break;
* V_20 = V_27 . V_30 . V_31 . V_32 ;
}
}
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
int F_15 ( T_1 V_33 ,
struct V_34 *
V_35 , T_1 V_36 ,
T_2 * V_37 )
{
int V_5 = 0 ;
int V_38 = 0 ;
int V_39 = 0 ;
struct V_23 V_40 ;
T_1 V_41 = 0 ;
T_1 V_42 = 0 ;
struct V_26 V_27 ;
struct V_1 * V_6 = NULL ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_2 V_49 ;
struct V_3 * V_50 ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
bool V_51 = false ;
F_3 ( V_35 != NULL ) ;
F_3 ( V_37 != NULL ) ;
F_3 ( V_36 >= sizeof( struct V_34 ) ) ;
F_3 ( V_10 > 0 ) ;
* V_37 = 0 ;
if ( ! V_8 || ! V_8 -> V_47 ) {
V_5 = - V_28 ;
F_6 ( L_2 , V_15 ) ;
} else {
V_48 = V_8 -> V_47 ;
}
if ( ! V_5 ) {
V_5 = F_16 ( V_33 , V_48 , & V_46 ) ;
if ( ! V_5 ) {
V_5 = F_17 ( V_46 , ( T_2 * ) & V_49 ) ;
V_5 = F_18 ( V_46 , & V_50 ) ;
if ( V_49 != V_52 )
V_5 = - V_14 ;
if ( ! V_5 )
V_35 -> V_53 = V_54 ;
}
}
if ( V_5 )
goto V_55;
if ( V_8 && V_8 -> V_1 ) {
V_6 = V_8 -> V_1 ;
} else {
F_19 ( V_9 , L_3 , V_15 ) ;
goto V_55;
}
F_12 ( V_6 ) ;
while ( V_38 == 0 ) {
V_38 = F_13 ( V_41 ++ ,
V_56 ,
& V_40 ) ;
if ( V_38 != 0 )
break;
V_42 ++ ;
if ( V_51 != false )
continue;
V_39 = F_14 ( V_6 -> V_13 ,
(struct V_23 * ) & V_40 ,
V_56 , & V_27 ) ;
if ( ! V_39 ) {
if ( V_36 <
sizeof( struct V_43 ) ) {
* V_35 = V_27 . V_30 . V_57 ;
} else {
V_44 = (struct V_43 * )
V_35 ;
* V_44 = V_27 . V_30 . V_58 ;
}
F_19 ( V_9 , L_4 ,
V_15 , V_35 -> V_53 ) ;
if ( V_49 == V_52 ) {
if ( V_35 -> V_53 ==
V_59 )
V_51 = true ;
} else if ( V_49 == V_60 ) {
if ( V_35 -> V_53 ==
V_61 )
V_51 = true ;
}
V_35 -> V_53 = V_54 ;
} else {
F_19 ( V_9 , L_5
L_6 , V_15 , V_39 ) ;
V_5 = - V_14 ;
}
}
* V_37 = V_42 ;
if ( V_51 == false ) {
F_19 ( V_9 , L_7
L_8 , V_15 ) ;
V_35 -> V_53 = V_54 ;
}
V_55:
return V_5 ;
}
void F_20 ( void )
{
F_3 ( V_10 > 0 ) ;
V_10 -- ;
if ( V_10 == 0 )
F_21 () ;
F_9 ( V_10 >= 0 ) ;
}
int F_22 ( struct V_1 * V_62 ,
T_1 * V_63 )
{
int V_5 = - V_14 ;
struct V_1 * V_6 = (struct V_1 * ) V_62 ;
F_3 ( V_10 > 0 ) ;
F_3 ( V_63 != NULL ) ;
* V_63 = ( T_1 ) NULL ;
if ( V_6 ) {
* V_63 = ( T_1 ) V_6 -> V_13 ;
V_5 = 0 ;
}
F_9 ( ( ! V_5 && * V_63 != ( T_1 ) NULL ) ||
( V_5 && * V_63 == ( T_1 ) NULL ) ) ;
return V_5 ;
}
bool F_23 ( void )
{
bool V_64 = true ;
bool V_65 = false ;
F_3 ( V_10 >= 0 ) ;
if ( V_10 == 0 ) {
V_65 = F_24 () ;
if ( ! V_65 )
V_64 = false ;
}
if ( V_64 )
V_10 ++ ;
F_9 ( ( V_64 && ( V_10 > 0 ) ) || ( ! V_64 && ( V_10 >= 0 ) ) ) ;
return V_64 ;
}
int F_25 ( struct V_66 * * V_67 ,
T_1 V_68 , T_1 * V_69 ,
T_1 V_70 )
{
int V_5 ;
struct V_71 * V_72 [ V_73 ] ;
T_1 V_74 ;
F_3 ( V_68 < V_73 ) ;
for ( V_74 = 0 ; V_74 < V_68 ; V_74 ++ )
V_72 [ V_74 ] = V_67 [ V_74 ] -> V_75 ;
V_5 = F_26 ( V_72 , V_68 , V_70 ,
V_69 ) ;
return V_5 ;
}
