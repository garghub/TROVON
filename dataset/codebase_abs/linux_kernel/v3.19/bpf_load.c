static int F_1 ( const char * V_1 , struct V_2 * V_3 , int V_4 )
{
int V_5 ;
bool V_6 = strncmp ( V_1 , L_1 , 6 ) == 0 ;
if ( ! V_6 )
return - 1 ;
V_5 = F_2 ( V_7 ,
V_3 , V_4 , V_8 ) ;
if ( V_5 < 0 ) {
printf ( L_2 , V_9 , V_10 ) ;
return - 1 ;
}
V_11 [ V_12 ++ ] = V_5 ;
return 0 ;
}
static int F_3 ( struct V_13 * V_14 , int V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 / sizeof( struct V_13 ) ; V_16 ++ ) {
V_17 [ V_16 ] = F_4 ( V_14 [ V_16 ] . type ,
V_14 [ V_16 ] . V_18 ,
V_14 [ V_16 ] . V_19 ,
V_14 [ V_16 ] . V_20 ) ;
if ( V_17 [ V_16 ] < 0 )
return 1 ;
}
return 0 ;
}
static int F_5 ( T_1 * V_21 , int V_16 , T_2 * V_22 , char * * V_23 ,
T_3 * V_24 , T_4 * * V_25 )
{
T_5 * V_26 ;
V_26 = F_6 ( V_21 , V_16 ) ;
if ( ! V_26 )
return 1 ;
if ( F_7 ( V_26 , V_24 ) != V_24 )
return 2 ;
* V_23 = F_8 ( V_21 , V_22 -> V_27 , V_24 -> V_28 ) ;
if ( ! * V_23 || ! V_24 -> V_29 )
return 3 ;
* V_25 = F_9 ( V_26 , 0 ) ;
if ( ! * V_25 || F_9 ( V_26 , * V_25 ) != NULL )
return 4 ;
return 0 ;
}
static int F_10 ( T_4 * V_25 , T_4 * V_30 ,
T_3 * V_24 , struct V_2 * V_31 )
{
int V_16 , V_32 ;
V_32 = V_24 -> V_29 / V_24 -> V_33 ;
for ( V_16 = 0 ; V_16 < V_32 ; V_16 ++ ) {
T_6 V_34 ;
T_7 V_35 ;
unsigned int V_36 ;
F_11 ( V_25 , V_16 , & V_35 ) ;
V_36 = V_35 . V_37 / sizeof( struct V_2 ) ;
F_12 ( V_30 , F_13 ( V_35 . V_38 ) , & V_34 ) ;
if ( V_31 [ V_36 ] . V_39 != ( V_40 | V_41 | V_42 ) ) {
printf ( L_3 ,
V_36 , V_31 [ V_36 ] . V_39 ) ;
return 1 ;
}
V_31 [ V_36 ] . V_43 = V_44 ;
V_31 [ V_36 ] . V_45 = V_17 [ V_34 . V_46 / sizeof( struct V_13 ) ] ;
}
return 0 ;
}
int F_14 ( char * V_47 )
{
int V_5 , V_16 ;
T_1 * V_21 ;
T_2 V_22 ;
T_3 V_24 , V_48 ;
T_4 * V_25 , * V_49 , * V_30 = NULL ;
char * V_23 , * V_50 ;
if ( F_15 ( V_51 ) == V_52 )
return 1 ;
V_5 = F_16 ( V_47 , V_53 , 0 ) ;
if ( V_5 < 0 )
return 1 ;
V_21 = F_17 ( V_5 , V_54 , NULL ) ;
if ( ! V_21 )
return 1 ;
if ( F_18 ( V_21 , & V_22 ) != & V_22 )
return 1 ;
for ( V_16 = 1 ; V_16 < V_22 . V_55 ; V_16 ++ ) {
if ( F_5 ( V_21 , V_16 , & V_22 , & V_23 , & V_24 , & V_25 ) )
continue;
if ( 0 )
printf ( L_4 ,
V_16 , V_23 , V_25 -> V_56 , V_25 -> V_57 ,
V_24 . V_58 , ( int ) V_24 . V_59 ) ;
if ( strcmp ( V_23 , L_5 ) == 0 ) {
V_60 [ V_16 ] = true ;
memcpy ( V_8 , V_25 -> V_56 , V_25 -> V_57 ) ;
} else if ( strcmp ( V_23 , L_6 ) == 0 ) {
V_60 [ V_16 ] = true ;
if ( F_3 ( V_25 -> V_56 , V_25 -> V_57 ) )
return 1 ;
} else if ( V_24 . V_61 == V_62 ) {
V_30 = V_25 ;
}
}
for ( V_16 = 1 ; V_16 < V_22 . V_55 ; V_16 ++ ) {
if ( F_5 ( V_21 , V_16 , & V_22 , & V_23 , & V_24 , & V_25 ) )
continue;
if ( V_24 . V_61 == V_63 ) {
struct V_2 * V_64 ;
if ( F_5 ( V_21 , V_24 . V_65 , & V_22 , & V_50 ,
& V_48 , & V_49 ) )
continue;
V_64 = (struct V_2 * ) V_49 -> V_56 ;
V_60 [ V_24 . V_65 ] = true ;
V_60 [ V_16 ] = true ;
if ( F_10 ( V_25 , V_30 , & V_24 , V_64 ) )
continue;
if ( memcmp ( V_50 , L_7 , 7 ) == 0 ||
memcmp ( V_50 , L_1 , 6 ) == 0 )
F_1 ( V_50 , V_64 , V_49 -> V_57 ) ;
}
}
for ( V_16 = 1 ; V_16 < V_22 . V_55 ; V_16 ++ ) {
if ( V_60 [ V_16 ] )
continue;
if ( F_5 ( V_21 , V_16 , & V_22 , & V_23 , & V_24 , & V_25 ) )
continue;
if ( memcmp ( V_23 , L_7 , 7 ) == 0 ||
memcmp ( V_23 , L_1 , 6 ) == 0 )
F_1 ( V_23 , V_25 -> V_56 , V_25 -> V_57 ) ;
}
F_19 ( V_5 ) ;
return 0 ;
}
