int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
V_6 = F_3 ( sizeof( struct V_1 ) , V_10 ) ;
if ( V_6 ) {
V_5 = F_4 ( V_11 , & V_6 -> V_12 ) ;
if ( ! V_5 ) {
if ( V_8 ) {
V_8 -> V_1 = ( void * ) V_6 ;
} else {
V_5 = - V_13 ;
F_5 ( L_1 ,
V_14 ) ;
}
if ( ! V_5 ) {
* V_2 = V_6 ;
} else {
F_6 ( V_6 -> V_12 ) ;
F_7 ( V_6 ) ;
}
} else {
F_7 ( V_6 ) ;
}
} else {
V_5 = - V_15 ;
}
return V_5 ;
}
int F_8 ( struct V_1 * V_16 )
{
int V_5 = 0 ;
struct V_1 * V_6 = (struct V_1 * ) V_16 ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
if ( V_16 -> V_12 )
F_6 ( V_16 -> V_12 ) ;
F_7 ( V_6 ) ;
if ( V_8 ) {
V_8 -> V_1 = NULL ;
} else {
V_5 = - V_13 ;
F_5 ( L_1 , V_14 ) ;
}
return V_5 ;
}
int F_9 ( T_1 V_17 , struct V_18 * V_19 ,
T_1 V_20 , T_1 * V_21 )
{
int V_5 = 0 ;
struct V_22 V_23 ;
T_1 V_24 = 0 ;
struct V_25 V_26 ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
* V_21 = 0 ;
if ( ! V_8 || ! V_8 -> V_1 ) {
F_5 ( L_2 , V_14 ) ;
return - V_27 ;
}
V_6 = V_8 -> V_1 ;
while ( ! V_5 ) {
V_5 = F_10 ( V_24 ++ , V_28 ,
& V_23 ) ;
if ( V_5 )
break;
* V_21 = V_24 ;
if ( V_17 == ( V_24 - 1 ) ) {
V_5 = F_11 ( V_6 -> V_12 ,
& V_23 , V_28 , & V_26 ) ;
if ( V_5 )
break;
* V_19 = V_26 . V_29 . V_30 . V_31 ;
}
}
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
int F_12 ( T_1 V_32 ,
struct V_33 *
V_34 , T_1 V_35 ,
T_2 * V_36 )
{
int V_5 = 0 ;
int V_37 = 0 ;
int V_38 = 0 ;
struct V_22 V_39 ;
T_1 V_40 = 0 ;
T_1 V_41 = 0 ;
struct V_25 V_26 ;
struct V_1 * V_6 = NULL ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_2 V_48 ;
struct V_3 * V_49 ;
struct V_7 * V_8 = F_2 ( V_9 ) ;
bool V_50 = false ;
* V_36 = 0 ;
if ( ! V_8 || ! V_8 -> V_46 ) {
V_5 = - V_27 ;
F_5 ( L_2 , V_14 ) ;
} else {
V_47 = V_8 -> V_46 ;
}
if ( ! V_5 ) {
V_5 = F_13 ( V_32 , V_47 , & V_45 ) ;
if ( ! V_5 ) {
V_5 = F_14 ( V_45 , ( T_2 * ) & V_48 ) ;
V_5 = F_15 ( V_45 , & V_49 ) ;
if ( V_48 != V_51 )
V_5 = - V_13 ;
if ( ! V_5 )
V_34 -> V_52 = V_53 ;
}
}
if ( V_5 )
goto V_54;
if ( V_8 && V_8 -> V_1 ) {
V_6 = V_8 -> V_1 ;
} else {
F_16 ( V_9 , L_3 , V_14 ) ;
goto V_54;
}
while ( V_37 == 0 ) {
V_37 = F_10 ( V_40 ++ ,
V_55 ,
& V_39 ) ;
if ( V_37 != 0 )
break;
V_41 ++ ;
if ( V_50 != false )
continue;
V_38 = F_11 ( V_6 -> V_12 ,
(struct V_22 * ) & V_39 ,
V_55 , & V_26 ) ;
if ( ! V_38 ) {
if ( V_35 <
sizeof( struct V_42 ) ) {
* V_34 = V_26 . V_29 . V_56 ;
} else {
V_43 = (struct V_42 * )
V_34 ;
* V_43 = V_26 . V_29 . V_57 ;
}
F_16 ( V_9 , L_4 ,
V_14 , V_34 -> V_52 ) ;
if ( V_48 == V_51 ) {
if ( V_34 -> V_52 ==
V_58 )
V_50 = true ;
} else if ( V_48 == V_59 ) {
if ( V_34 -> V_52 ==
V_60 )
V_50 = true ;
}
V_34 -> V_52 = V_53 ;
} else {
F_16 ( V_9 , L_5
L_6 , V_14 , V_38 ) ;
V_5 = - V_13 ;
}
}
* V_36 = V_41 ;
if ( V_50 == false ) {
F_16 ( V_9 , L_7
L_8 , V_14 ) ;
V_34 -> V_52 = V_53 ;
}
V_54:
return V_5 ;
}
void F_17 ( void )
{
V_61 -- ;
if ( V_61 == 0 )
F_18 () ;
}
int F_19 ( struct V_1 * V_62 ,
T_1 * V_63 )
{
int V_5 = - V_13 ;
struct V_1 * V_6 = (struct V_1 * ) V_62 ;
* V_63 = ( T_1 ) NULL ;
if ( V_6 ) {
* V_63 = ( T_1 ) V_6 -> V_12 ;
V_5 = 0 ;
}
return V_5 ;
}
bool F_20 ( void )
{
bool V_64 = true ;
if ( V_61 == 0 )
V_64 = F_21 () ;
if ( V_64 )
V_61 ++ ;
return V_64 ;
}
int F_22 ( struct V_65 * * V_66 ,
T_1 V_67 , T_1 * V_68 ,
T_1 V_69 )
{
int V_5 ;
struct V_70 * V_71 [ V_72 ] ;
T_1 V_73 ;
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ )
V_71 [ V_73 ] = V_66 [ V_73 ] -> V_74 ;
V_5 = F_23 ( V_71 , V_67 , V_69 ,
V_68 ) ;
return V_5 ;
}
