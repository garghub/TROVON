static struct V_1 * F_1 ( const char * V_2 , unsigned V_3 ,
char * V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_6 ;
char V_7 [ 4 + V_8 + 1 ] , * V_9 , * V_10 , * V_11 ;
char * V_12 = NULL , * V_13 = NULL ;
char V_14 = ':' ;
int V_15 ;
F_2 ( L_1 , V_3 , V_3 , V_2 ? : L_2 , V_4 ) ;
F_3 ( ! V_2 ) ;
if ( V_3 > V_8 ) {
F_4 ( L_3 ) ;
return F_5 ( - V_16 ) ;
}
V_5 = F_6 ( sizeof( struct V_1 ) + V_3 + 1 , V_17 ) ;
if ( ! V_5 ) {
F_4 ( L_4 ) ;
return F_5 ( - V_18 ) ;
}
memcpy ( V_5 -> V_2 , V_2 , V_3 ) ;
V_5 -> V_2 [ V_3 ] = 0 ;
F_7 ( & V_5 -> V_19 , 1 ) ;
F_8 ( & V_5 -> V_20 ) ;
F_9 ( & V_5 -> V_21 ) ;
F_8 ( & V_5 -> V_22 ) ;
F_10 ( & V_5 -> V_23 ) ;
F_8 ( & V_5 -> V_24 ) ;
F_11 ( & V_5 -> V_25 ) ;
if ( ! V_4 || strlen ( V_4 ) < 7 ) {
V_15 = F_12 ( L_5 , V_2 , V_3 , L_6 , & V_12 , NULL ) ;
if ( V_15 < 0 ) {
if ( V_15 == - V_26 || V_15 == - V_27 || V_15 == - V_28 )
V_15 = - V_29 ;
F_4 ( L_7 , V_15 ) ;
return F_5 ( V_15 ) ;
}
V_13 = V_12 ;
V_14 = ',' ;
} else {
V_13 = V_4 ;
}
do {
unsigned V_30 , V_31 , V_32 , V_33 ;
V_11 = strchr ( V_13 , V_14 ) ;
if ( V_11 )
* V_11 ++ = 0 ;
if ( sscanf ( V_13 , L_8 , & V_30 , & V_31 , & V_32 , & V_33 ) != 4 )
goto V_34;
if ( V_30 > 255 || V_31 > 255 || V_32 > 255 || V_33 > 255 )
goto V_34;
V_5 -> V_35 [ V_5 -> V_36 ++ ] . V_37 =
F_13 ( ( V_30 << 24 ) | ( V_31 << 16 ) | ( V_32 << 8 ) | V_33 ) ;
} while ( V_5 -> V_36 < V_38 && ( V_13 = V_11 ) );
memcpy ( V_7 , L_9 , 4 ) ;
V_10 = V_7 + 4 ;
V_9 = V_5 -> V_2 ;
do {
* V_10 ++ = toupper ( * V_9 ) ;
} while ( * V_9 ++ );
V_6 = F_14 ( V_7 ) ;
if ( F_15 ( V_6 ) ) {
F_16 ( L_10 ) ;
V_15 = F_17 ( V_6 ) ;
goto error;
}
V_5 -> V_39 = V_6 ;
F_16 ( L_11 ,
V_5 -> V_39 , F_18 ( V_5 -> V_39 ) ) ;
F_4 ( L_12 , V_5 ) ;
return V_5 ;
V_34:
F_19 ( V_40 L_13 ) ;
V_15 = - V_41 ;
error:
F_20 ( V_5 -> V_39 ) ;
F_21 ( V_12 ) ;
F_21 ( V_5 ) ;
F_4 ( L_7 , V_15 ) ;
return F_5 ( V_15 ) ;
}
struct V_1 * F_22 ( const char * V_2 , unsigned V_42 ,
char * V_4 , bool V_43 )
{
struct V_1 * V_5 ;
int V_15 ;
F_2 ( L_1 , V_42 , V_42 , V_2 ? : L_2 , V_4 ) ;
F_23 ( & V_44 ) ;
F_24 ( & V_45 ) ;
F_25 (cell, &afs_cells, link) {
if ( strncasecmp ( V_5 -> V_2 , V_2 , V_42 ) == 0 )
goto V_46;
}
F_26 ( & V_45 ) ;
V_5 = F_1 ( V_2 , V_42 , V_4 ) ;
if ( F_15 ( V_5 ) ) {
F_4 ( L_14 , F_17 ( V_5 ) ) ;
F_27 ( & V_44 ) ;
return V_5 ;
}
V_15 = F_28 ( V_5 ) ;
if ( V_15 < 0 )
goto error;
#ifdef F_29
V_5 -> V_47 = F_30 ( V_48 . V_49 ,
& V_50 ,
V_5 ) ;
#endif
F_31 ( & V_45 ) ;
F_32 ( & V_5 -> V_20 , & V_51 ) ;
F_33 ( & V_45 ) ;
F_23 ( & V_52 ) ;
F_32 ( & V_5 -> V_53 , & V_54 ) ;
F_27 ( & V_52 ) ;
F_27 ( & V_44 ) ;
F_4 ( L_12 , V_5 ) ;
return V_5 ;
error:
F_27 ( & V_44 ) ;
F_20 ( V_5 -> V_39 ) ;
F_21 ( V_5 ) ;
F_4 ( L_7 , V_15 ) ;
return F_5 ( V_15 ) ;
V_46:
if ( V_43 && ! F_15 ( V_5 ) )
F_34 ( V_5 ) ;
F_26 ( & V_45 ) ;
F_27 ( & V_44 ) ;
if ( V_43 ) {
F_4 ( L_12 , V_5 ) ;
return V_5 ;
}
F_4 ( L_15 ) ;
return F_5 ( - V_55 ) ;
}
int F_35 ( char * V_56 )
{
struct V_1 * V_57 , * V_58 ;
char * V_9 ;
F_2 ( L_2 ) ;
if ( ! V_56 ) {
F_4 ( L_16 ) ;
return 0 ;
}
V_9 = strchr ( V_56 , ':' ) ;
if ( ! V_9 )
F_16 ( L_17 ) ;
else
* V_9 ++ = 0 ;
V_58 = F_22 ( V_56 , strlen ( V_56 ) , V_9 , false ) ;
if ( F_15 ( V_58 ) ) {
F_4 ( L_14 , F_17 ( V_58 ) ) ;
return F_17 ( V_58 ) ;
}
F_31 ( & V_45 ) ;
V_57 = V_59 ;
V_59 = V_58 ;
F_33 ( & V_45 ) ;
F_36 ( V_57 ) ;
F_4 ( L_18 ) ;
return 0 ;
}
struct V_1 * F_37 ( const char * V_2 , unsigned V_42 ,
bool V_60 )
{
struct V_1 * V_5 ;
F_2 ( L_19 , V_42 , V_42 , V_2 ? : L_2 ) ;
F_38 ( & V_44 ) ;
F_24 ( & V_45 ) ;
if ( V_2 ) {
F_25 (cell, &afs_cells, link) {
if ( strncmp ( V_5 -> V_2 , V_2 , V_42 ) == 0 ) {
F_34 ( V_5 ) ;
goto V_61;
}
}
V_5 = F_5 ( - V_62 ) ;
if ( V_60 )
goto V_63;
V_61:
;
} else {
V_5 = V_59 ;
if ( ! V_5 ) {
V_5 = F_5 ( - V_29 ) ;
} else {
F_34 ( V_5 ) ;
}
}
F_26 ( & V_45 ) ;
F_39 ( & V_44 ) ;
F_4 ( L_12 , V_5 ) ;
return V_5 ;
V_63:
F_26 ( & V_45 ) ;
F_39 ( & V_44 ) ;
V_5 = F_22 ( V_2 , V_42 , NULL , true ) ;
F_4 ( L_12 , V_5 ) ;
return V_5 ;
}
void F_36 ( struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_2 ( L_20 , V_5 , F_40 ( & V_5 -> V_19 ) , V_5 -> V_2 ) ;
F_41 ( F_40 ( & V_5 -> V_19 ) , > , 0 ) ;
F_31 ( & V_45 ) ;
if ( F_42 ( ! F_43 ( & V_5 -> V_19 ) ) ) {
F_33 ( & V_45 ) ;
F_4 ( L_2 ) ;
return;
}
ASSERT ( F_44 ( & V_5 -> V_22 ) ) ;
ASSERT ( F_44 ( & V_5 -> V_24 ) ) ;
F_33 ( & V_45 ) ;
F_45 ( & V_64 ) ;
F_4 ( L_21 ) ;
}
static void F_46 ( struct V_1 * V_5 )
{
F_2 ( L_20 , V_5 , F_40 ( & V_5 -> V_19 ) , V_5 -> V_2 ) ;
F_41 ( F_40 ( & V_5 -> V_19 ) , >= , 0 ) ;
ASSERT ( F_44 ( & V_5 -> V_20 ) ) ;
if ( F_40 ( & V_5 -> V_19 ) > 0 ) {
F_47 ( V_65 , V_66 ) ;
F_16 ( L_22 , V_5 -> V_2 ) ;
F_48 ( V_67 ) ;
F_49 ( & V_64 , & V_65 ) ;
while ( F_40 ( & V_5 -> V_19 ) > 0 ) {
F_50 () ;
F_48 ( V_67 ) ;
}
F_51 ( & V_64 , & V_65 ) ;
F_48 ( V_68 ) ;
}
F_16 ( L_23 ) ;
F_41 ( F_40 ( & V_5 -> V_19 ) , == , 0 ) ;
ASSERT ( F_44 ( & V_5 -> V_22 ) ) ;
ASSERT ( F_44 ( & V_5 -> V_24 ) ) ;
F_52 ( V_5 ) ;
F_23 ( & V_52 ) ;
F_53 ( & V_5 -> V_53 ) ;
F_27 ( & V_52 ) ;
#ifdef F_29
F_54 ( V_5 -> V_47 , 0 ) ;
#endif
F_20 ( V_5 -> V_39 ) ;
F_21 ( V_5 ) ;
F_4 ( L_24 ) ;
}
void F_55 ( void )
{
struct V_1 * V_5 ;
F_2 ( L_2 ) ;
F_36 ( V_59 ) ;
F_23 ( & V_44 ) ;
while ( ! F_44 ( & V_51 ) ) {
V_5 = NULL ;
F_31 ( & V_45 ) ;
if ( ! F_44 ( & V_51 ) ) {
V_5 = F_56 ( V_51 . V_11 ,
struct V_1 , V_20 ) ;
F_53 ( & V_5 -> V_20 ) ;
}
F_33 ( & V_45 ) ;
if ( V_5 ) {
F_16 ( L_25 ,
V_5 -> V_2 , F_40 ( & V_5 -> V_19 ) ) ;
F_46 ( V_5 ) ;
}
}
F_27 ( & V_44 ) ;
F_4 ( L_2 ) ;
}
