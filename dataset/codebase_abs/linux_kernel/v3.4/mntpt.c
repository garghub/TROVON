int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_4 ;
T_1 V_5 ;
char * V_6 ;
int V_7 ;
F_2 ( L_1 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_2 , V_2 -> V_8 . V_10 ) ;
V_4 = F_3 ( F_4 ( V_2 ) -> V_11 , 0 ,
V_12 , V_3 ) ;
if ( F_5 ( V_4 ) ) {
V_7 = F_6 ( V_4 ) ;
goto V_13;
}
V_7 = - V_14 ;
if ( F_7 ( V_4 ) )
goto V_15;
V_6 = F_8 ( V_4 ) ;
V_5 = V_2 -> V_16 . V_5 ;
F_9 ( L_2 , ( int ) V_5 , ( int ) V_5 , V_6 ) ;
if ( V_5 > 2 &&
( V_6 [ 0 ] == '%' || V_6 [ 0 ] == '#' ) &&
V_6 [ V_5 - 1 ] == '.'
) {
F_9 ( L_3 ) ;
F_10 ( & V_2 -> V_17 ) ;
F_11 ( V_18 , & V_2 -> V_19 ) ;
V_2 -> V_20 . V_21 |= V_22 ;
F_12 ( & V_2 -> V_17 ) ;
}
V_7 = 0 ;
F_13 ( V_4 ) ;
V_15:
F_14 ( V_4 ) ;
V_13:
F_15 ( L_4 , V_7 ) ;
return V_7 ;
}
static struct V_23 * F_16 ( struct V_24 * V_25 ,
struct V_23 * V_23 ,
struct V_26 * V_27 )
{
F_2 ( L_5 ,
V_25 ,
V_23 ,
V_23 -> V_28 ,
V_23 -> V_28 ?
V_23 -> V_28 -> V_29 . V_30 : ( const unsigned char * ) L_6 ,
V_23 -> V_29 . V_30 ) ;
return F_17 ( - V_31 ) ;
}
static int F_18 ( struct V_24 * V_24 , struct V_32 * V_32 )
{
F_2 ( L_5 ,
V_24 , V_32 ,
V_32 -> V_33 . V_23 -> V_28 ,
V_32 -> V_33 . V_23 -> V_28 ?
V_32 -> V_33 . V_23 -> V_28 -> V_29 . V_30 :
( const unsigned char * ) L_6 ,
V_32 -> V_33 . V_23 -> V_29 . V_30 ) ;
return - V_31 ;
}
static struct V_34 * F_19 ( struct V_23 * V_35 )
{
struct V_36 * V_37 ;
struct V_34 * V_38 ;
struct V_1 * V_2 ;
struct V_4 * V_4 ;
char * V_39 , * V_40 ;
bool V_41 = false ;
int V_7 ;
F_2 ( L_7 , V_35 -> V_29 . V_30 ) ;
F_20 ( ! V_35 -> V_42 ) ;
V_7 = - V_43 ;
V_39 = ( char * ) F_21 ( V_44 ) ;
if ( ! V_39 )
goto V_45;
V_40 = ( char * ) F_21 ( V_44 ) ;
if ( ! V_40 )
goto V_46;
V_2 = F_22 ( V_35 -> V_42 ) ;
if ( F_23 ( V_47 , & V_2 -> V_19 ) ) {
static const char V_48 [] = L_8 ;
unsigned V_5 = V_35 -> V_29 . V_49 ;
V_7 = - V_50 ;
if ( V_5 < 2 || V_5 > V_51 )
goto V_52;
if ( V_35 -> V_29 . V_30 [ 0 ] == '.' ) {
V_39 [ 0 ] = '#' ;
memcpy ( V_39 + 1 , V_35 -> V_29 . V_30 , V_5 - 1 ) ;
memcpy ( V_39 + V_5 , V_48 ,
sizeof( V_48 ) ) ;
V_41 = true ;
} else {
V_39 [ 0 ] = '%' ;
memcpy ( V_39 + 1 , V_35 -> V_29 . V_30 , V_5 ) ;
memcpy ( V_39 + V_5 + 1 , V_48 ,
sizeof( V_48 ) ) ;
}
} else {
T_2 V_5 = F_24 ( V_35 -> V_42 ) ;
char * V_6 ;
V_7 = - V_53 ;
if ( V_5 > V_54 - 1 )
goto V_52;
V_4 = F_25 ( V_35 -> V_42 -> V_11 , 0 , NULL ) ;
if ( F_5 ( V_4 ) ) {
V_7 = F_6 ( V_4 ) ;
goto V_52;
}
V_7 = - V_14 ;
if ( F_7 ( V_4 ) )
goto error;
V_6 = F_26 ( V_4 ) ;
memcpy ( V_39 , V_6 , V_5 ) ;
F_27 ( V_6 ) ;
F_14 ( V_4 ) ;
V_4 = NULL ;
}
V_37 = F_28 ( V_35 -> V_55 ) ;
memcpy ( V_40 , L_9 , 5 ) ;
strcpy ( V_40 + 5 , V_37 -> V_56 -> V_57 -> V_30 ) ;
if ( V_37 -> V_56 -> type == V_58 || V_41 )
strcat ( V_40 , L_10 ) ;
F_9 ( L_11 , V_39 , V_40 ) ;
V_38 = F_29 ( & V_59 , 0 , V_39 , V_40 ) ;
F_9 ( L_12 , V_38 ) ;
F_30 ( ( unsigned long ) V_39 ) ;
F_30 ( ( unsigned long ) V_40 ) ;
F_15 ( L_13 , V_38 ) ;
return V_38 ;
error:
F_14 ( V_4 ) ;
V_52:
F_30 ( ( unsigned long ) V_40 ) ;
V_46:
F_30 ( ( unsigned long ) V_39 ) ;
V_45:
F_15 ( L_4 , V_7 ) ;
return F_17 ( V_7 ) ;
}
struct V_34 * F_31 ( struct V_60 * V_60 )
{
struct V_34 * V_61 ;
F_2 ( L_7 , V_60 -> V_23 -> V_29 . V_30 ) ;
V_61 = F_19 ( V_60 -> V_23 ) ;
if ( F_5 ( V_61 ) )
return V_61 ;
F_32 ( V_61 ) ;
F_33 ( V_61 , & V_62 ) ;
F_34 ( V_63 , & V_64 ,
V_65 * V_66 ) ;
F_15 ( L_13 , V_61 ) ;
return V_61 ;
}
static void F_35 ( struct V_67 * V_68 )
{
F_2 ( L_6 ) ;
if ( ! F_36 ( & V_62 ) ) {
F_37 ( & V_62 ) ;
F_34 ( V_63 , & V_64 ,
V_65 * V_66 ) ;
}
F_15 ( L_6 ) ;
}
void F_38 ( void )
{
F_2 ( L_6 ) ;
ASSERT ( F_36 ( & V_62 ) ) ;
F_39 ( & V_64 ) ;
}
