void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
F_2 ( V_2 -> V_5 [ V_3 ] ) ;
F_3 ( V_6 , V_2 ) ;
}
struct V_1 * F_4 ( struct V_1 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_6 , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = 0 ;
if ( V_7 ) {
int V_3 ;
memcpy ( V_2 , V_7 , sizeof( * V_2 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
F_6 ( V_2 -> V_5 [ V_3 ] ) ;
}
F_7 ( & V_2 -> V_9 , 1 ) ;
return V_2 ;
}
int F_8 ( struct V_10 * V_11 , T_1 V_12 , T_2 * V_13 , T_2 * V_14 )
{
int V_15 , V_16 ;
int V_17 ;
switch ( V_12 ) {
case V_18 :
V_17 = sizeof( struct V_19 ) ;
V_15 = F_9 ( struct V_19 , V_13 ) ;
V_16 = F_9 ( struct V_19 , V_20 ) ;
break;
case V_21 :
V_17 = sizeof( struct V_22 ) ;
V_15 = F_9 ( struct V_22 , V_13 ) ;
V_16 = F_9 ( struct V_22 , V_20 ) ;
break;
case V_23 :
if ( ! F_10 ( V_11 , sizeof( struct V_24 ) ) )
return - V_25 ;
* V_13 = F_11 ( F_12 ( * ( V_26 * ) ( F_13 ( V_11 ) + 2 ) ) ) ;
* V_14 = 0 ;
return 0 ;
default:
return 1 ;
}
if ( ! F_10 ( V_11 , V_17 ) )
return - V_25 ;
* V_13 = * ( T_2 * ) ( F_13 ( V_11 ) + V_15 ) ;
* V_14 = * ( T_2 * ) ( F_13 ( V_11 ) + V_16 ) ;
return 0 ;
}
int F_14 ( struct V_27 * V_28 , struct V_10 * V_11 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
int V_31 ;
V_31 = V_28 -> V_32 -> V_33 -> V_34 ( V_28 , V_11 ) ;
if ( V_31 )
return V_31 ;
if ( V_28 -> V_35 . V_36 == V_37 ) {
V_30 = F_15 ( V_28 , F_16 ( V_11 ) -> V_38 ) ;
if ( V_30 == NULL )
return - V_39 ;
}
V_11 -> V_38 = V_30 -> V_33 -> V_40 ;
return V_30 -> V_41 ( V_28 , V_11 ) ;
}
int F_17 ( struct V_10 * V_11 , int V_12 , T_2 V_13 , int V_42 )
{
struct V_43 * V_43 = F_18 ( V_11 -> V_44 ) ;
int V_31 ;
T_2 V_14 ;
T_2 V_45 ;
struct V_27 * V_28 ;
T_3 * V_46 ;
struct V_29 * V_30 ;
unsigned int V_36 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( V_42 < 0 ) {
V_48 = 1 ;
V_28 = F_19 ( V_11 ) ;
V_14 = F_20 ( V_11 ) -> V_14 . V_49 . V_50 ;
goto V_51;
}
if ( ! V_11 -> V_2 || F_21 ( & V_11 -> V_2 -> V_9 ) != 1 ) {
struct V_1 * V_2 ;
V_2 = F_4 ( V_11 -> V_2 ) ;
if ( ! V_2 ) {
F_22 ( V_43 , V_52 ) ;
goto V_53;
}
if ( V_11 -> V_2 )
F_23 ( V_11 -> V_2 ) ;
V_11 -> V_2 = V_2 ;
}
V_46 = ( T_3 * ) ( F_24 ( V_11 ) +
F_25 ( V_11 ) -> V_54 ) ;
V_36 = F_25 ( V_11 ) -> V_36 ;
V_14 = 0 ;
if ( ! V_13 && ( V_31 = F_8 ( V_11 , V_12 , & V_13 , & V_14 ) ) != 0 ) {
F_22 ( V_43 , V_55 ) ;
goto V_53;
}
do {
if ( V_11 -> V_2 -> V_4 == V_56 ) {
F_22 ( V_43 , V_57 ) ;
goto V_53;
}
V_28 = F_26 ( V_43 , V_11 -> V_58 , V_46 , V_13 , V_12 , V_36 ) ;
if ( V_28 == NULL ) {
F_22 ( V_43 , V_59 ) ;
F_27 ( V_11 , V_36 , V_13 , V_14 ) ;
goto V_53;
}
V_11 -> V_2 -> V_5 [ V_11 -> V_2 -> V_4 ++ ] = V_28 ;
F_28 ( & V_28 -> V_60 ) ;
if ( F_29 ( V_28 -> V_61 . V_62 == V_63 ) ) {
F_22 ( V_43 , V_64 ) ;
goto V_65;
}
if ( F_29 ( V_28 -> V_61 . V_62 != V_66 ) ) {
F_22 ( V_43 , V_67 ) ;
goto V_65;
}
if ( ( V_28 -> V_68 ? V_28 -> V_68 -> V_42 : 0 ) != V_42 ) {
F_22 ( V_43 , V_69 ) ;
goto V_65;
}
if ( V_28 -> V_70 -> V_71 ( V_28 , V_11 , V_14 ) ) {
F_22 ( V_43 , V_72 ) ;
goto V_65;
}
if ( F_30 ( V_28 ) ) {
F_22 ( V_43 , V_73 ) ;
goto V_65;
}
F_31 ( & V_28 -> V_60 ) ;
V_45 = F_11 ( F_32 ( V_28 , V_14 ) ) ;
F_20 ( V_11 ) -> V_14 . V_49 . V_50 = V_14 ;
F_20 ( V_11 ) -> V_14 . V_49 . V_74 = V_45 ;
F_33 ( V_11 ) ;
V_12 = V_28 -> type -> V_49 ( V_28 , V_11 ) ;
if ( V_12 == - V_75 )
return 0 ;
V_51:
F_28 ( & V_28 -> V_60 ) ;
if ( V_12 <= 0 ) {
if ( V_12 == - V_76 ) {
F_34 ( V_28 , V_11 ,
V_28 -> type -> V_77 ) ;
V_28 -> V_78 . V_79 ++ ;
}
F_22 ( V_43 , V_80 ) ;
goto V_65;
}
V_42 = 0 ;
if ( V_48 && V_28 -> V_70 -> V_81 ( V_28 , V_11 , V_14 ) ) {
F_22 ( V_43 , V_72 ) ;
goto V_65;
}
V_28 -> V_70 -> V_82 ( V_28 , V_14 ) ;
V_28 -> V_83 . V_84 += V_11 -> V_4 ;
V_28 -> V_83 . V_85 ++ ;
F_31 ( & V_28 -> V_60 ) ;
F_16 ( V_11 ) -> V_38 = V_12 ;
V_30 = V_28 -> V_30 ;
if ( V_28 -> V_35 . V_36 == V_37 ) {
V_30 = F_15 ( V_28 , F_16 ( V_11 ) -> V_38 ) ;
if ( V_30 == NULL )
goto V_53;
}
if ( V_30 -> V_49 ( V_28 , V_11 ) ) {
F_22 ( V_43 , V_86 ) ;
goto V_53;
}
if ( V_28 -> V_32 -> V_87 & V_88 ) {
V_47 = 1 ;
break;
}
V_46 = & V_28 -> V_89 . V_46 ;
V_36 = V_28 -> V_32 -> V_33 -> V_36 ;
V_31 = F_8 ( V_11 , V_12 , & V_13 , & V_14 ) ;
if ( V_31 < 0 ) {
F_22 ( V_43 , V_55 ) ;
goto V_53;
}
} while ( ! V_31 );
F_35 ( V_11 ) ;
if ( V_47 ) {
F_36 ( V_11 ) ;
F_37 ( V_11 ) ;
return 0 ;
} else {
return V_28 -> V_30 -> V_33 -> V_90 ( V_11 , V_48 ) ;
}
V_65:
F_31 ( & V_28 -> V_60 ) ;
V_53:
F_38 ( V_11 ) ;
return 0 ;
}
int F_39 ( struct V_10 * V_11 , int V_12 )
{
return F_17 ( V_11 , V_12 , 0 , - 1 ) ;
}
void T_4 F_40 ( void )
{
V_6 = F_41 ( L_1 ,
sizeof( struct V_1 ) ,
0 , V_91 | V_92 ,
NULL ) ;
}
