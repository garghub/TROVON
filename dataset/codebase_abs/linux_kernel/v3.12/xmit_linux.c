T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - ( ( V_4 ) ( V_2 -> V_5 ) -
( V_4 ) ( V_2 -> V_6 ) ) ;
}
void F_2 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
V_9 ;
V_2 -> V_10 = V_8 ;
V_2 -> V_5 = V_8 -> V_11 ;
V_2 -> V_6 = V_8 -> V_11 ;
V_2 -> V_12 = V_8 -> V_13 ;
V_2 -> V_3 = V_8 -> V_13 ;
V_2 -> V_14 = V_2 -> V_6 ;
V_15 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_2 * V_16 , T_1 V_17 )
{
T_1 V_13 = 0 ;
V_9 ;
V_13 = F_1 ( V_2 ) ;
V_13 = ( V_17 > V_13 ) ? V_13 : V_17 ;
if ( V_16 )
F_4 ( V_2 -> V_10 , V_2 -> V_3 - V_2 -> V_12 , V_16 , V_13 ) ;
V_2 -> V_5 += V_13 ;
V_2 -> V_12 -= V_13 ;
V_15 ;
return V_13 ;
}
int F_5 ( struct V_1 * V_2 )
{
V_9 ;
if ( V_2 -> V_12 == 0 ) {
V_15 ;
return true ;
}
V_15 ;
return false ;
}
void F_6 ( struct V_7 * V_10 , struct V_18 * V_19 )
{
}
int F_7 ( struct V_20 * V_21 , struct V_22 * V_23 , T_3 V_24 )
{
int V_25 ;
V_23 -> V_26 = F_8 ( V_24 ) ;
if ( V_23 -> V_26 == NULL )
return V_27 ;
V_23 -> V_28 = ( T_2 * ) F_9 ( ( V_4 ) ( V_23 -> V_26 ) , V_29 ) ;
V_23 -> V_30 = 0 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
V_23 -> V_31 [ V_25 ] = F_10 ( 0 , V_32 ) ;
if ( V_23 -> V_31 [ V_25 ] == NULL ) {
F_11 ( L_1 ) ;
return V_27 ;
}
}
return V_33 ;
}
void F_12 ( struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_34 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
F_13 ( V_23 -> V_31 [ V_25 ] ) ;
F_14 ( V_23 -> V_26 ) ;
}
void F_15 ( struct V_20 * V_21 , struct V_7 * V_10 )
{
#if ( V_35 >= F_16 ( 2 , 6 , 35 ) )
T_4 V_36 ;
struct V_37 * V_38 = & V_21 -> V_39 ;
V_36 = F_17 ( V_10 ) ;
if ( V_21 -> V_40 . V_41 ) {
if ( F_18 ( V_21 -> V_42 , V_36 ) &&
( V_38 -> V_43 [ V_36 ] . V_44 < V_45 ) )
F_19 ( V_21 -> V_42 , V_36 ) ;
} else {
if ( F_18 ( V_21 -> V_42 , V_36 ) )
F_19 ( V_21 -> V_42 , V_36 ) ;
}
#else
if ( F_20 ( V_21 -> V_42 ) )
F_21 ( V_21 -> V_42 ) ;
#endif
F_22 ( V_10 ) ;
}
void F_23 ( struct V_20 * V_21 , struct V_46 * V_47 )
{
if ( V_47 -> V_10 )
F_15 ( V_21 , V_47 -> V_10 ) ;
V_47 -> V_10 = NULL ;
}
void F_24 ( struct V_20 * V_21 )
{
unsigned long V_48 ;
struct V_37 * V_38 ;
if ( ! V_21 )
return;
V_38 = & V_21 -> V_39 ;
F_25 ( & V_38 -> V_49 , & V_48 ) ;
if ( F_26 ( V_21 ) )
F_27 ( & V_38 -> V_50 ) ;
F_28 ( & V_38 -> V_49 , & V_48 ) ;
}
static void F_29 ( struct V_20 * V_21 , struct V_7 * V_10 )
{
struct V_37 * V_38 = & V_21 -> V_39 ;
T_4 V_36 ;
V_36 = F_17 ( V_10 ) ;
if ( V_21 -> V_40 . V_41 ) {
if ( V_38 -> V_43 [ V_36 ] . V_44 > V_45 )
F_30 ( V_21 -> V_42 , V_36 ) ;
} else {
if ( V_38 -> V_51 <= 4 ) {
if ( ! F_31 ( F_32 ( V_21 -> V_42 , V_36 ) ) )
F_30 ( V_21 -> V_42 , V_36 ) ;
}
}
}
static int F_33 ( struct V_20 * V_21 , struct V_7 * V_52 )
{
struct V_53 * V_54 = & V_21 -> V_55 ;
struct V_37 * V_38 = & V_21 -> V_39 ;
unsigned long V_48 ;
struct V_56 * V_57 , * V_58 ;
struct V_7 * V_59 ;
struct V_60 * V_61 = NULL ;
T_5 V_62 ;
F_25 ( & V_54 -> V_63 , & V_48 ) ;
V_57 = & V_54 -> V_64 ;
V_58 = F_34 ( V_57 ) ;
while ( ! F_35 ( V_57 , V_58 ) ) {
V_61 = F_36 ( V_58 , struct V_60 , V_64 ) ;
V_58 = F_34 ( V_58 ) ;
if ( ! memcmp ( V_61 -> V_65 , & V_52 -> V_11 [ 6 ] , 6 ) )
continue;
V_59 = F_37 ( V_52 , V_66 ) ;
if ( V_59 ) {
memcpy ( V_59 -> V_11 , V_61 -> V_65 , 6 ) ;
V_62 = F_38 ( V_21 , & V_59 ) ;
if ( V_62 < 0 ) {
F_11 ( L_2 , V_67 , __LINE__ ) ;
V_38 -> V_68 ++ ;
F_22 ( V_59 ) ;
} else {
V_38 -> V_69 ++ ;
}
} else {
F_11 ( L_3 , V_67 , __LINE__ ) ;
V_38 -> V_68 ++ ;
F_28 ( & V_54 -> V_63 , & V_48 ) ;
return false ;
}
}
F_28 ( & V_54 -> V_63 , & V_48 ) ;
F_22 ( V_52 ) ;
return true ;
}
int F_39 ( struct V_7 * V_10 , struct V_70 * V_42 )
{
struct V_20 * V_21 = (struct V_20 * ) F_40 ( V_42 ) ;
struct V_37 * V_38 = & V_21 -> V_39 ;
struct V_71 * V_72 = & V_21 -> V_73 ;
T_5 V_62 = 0 ;
V_9 ;
F_41 ( V_74 , V_75 , ( L_4 ) ) ;
if ( F_42 ( V_21 ) == false ) {
F_41 ( V_76 , V_77 , ( L_5 ) ) ;
goto V_78;
}
F_29 ( V_21 , V_10 ) ;
if ( ! V_79 && F_43 ( V_72 , V_80 ) &&
( F_44 ( V_10 -> V_11 ) || F_45 ( V_10 -> V_11 ) ) &&
( V_21 -> V_40 . V_41 == 0 ) ) {
if ( V_38 -> V_51 > ( V_81 / 4 ) ) {
V_62 = F_33 ( V_21 , V_10 ) ;
if ( V_62 )
goto exit;
}
}
V_62 = F_38 ( V_21 , & V_10 ) ;
if ( V_62 < 0 )
goto V_78;
V_38 -> V_69 ++ ;
F_41 ( V_76 , V_75 , ( L_6 , ( T_3 ) V_38 -> V_69 ) ) ;
goto exit;
V_78:
V_38 -> V_68 ++ ;
F_22 ( V_10 ) ;
F_41 ( V_76 , V_82 , ( L_7 , ( T_3 ) V_38 -> V_68 ) ) ;
exit:
V_15 ;
return 0 ;
}
