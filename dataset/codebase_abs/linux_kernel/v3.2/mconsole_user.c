static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
V_5 . V_8 = V_3 ;
V_5 . V_9 = strlen ( V_3 ) ;
V_7 . V_10 = & ( V_2 -> V_11 ) ;
V_7 . V_12 = V_2 -> V_13 ;
V_7 . V_14 = & V_5 ;
V_7 . V_15 = 1 ;
V_7 . V_16 = NULL ;
V_7 . V_17 = 0 ;
V_7 . V_18 = 0 ;
return F_2 ( V_2 -> V_19 , & V_7 , 0 ) ;
}
static struct V_20 * F_3 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_4 ( V_23 ) ; V_22 ++ ) {
V_21 = & V_23 [ V_22 ] ;
if ( ! strncmp ( V_2 -> V_24 . V_25 , V_21 -> V_26 ,
strlen ( V_21 -> V_26 ) ) ) {
return V_21 ;
}
}
return NULL ;
}
int F_5 ( int V_27 , struct V_1 * V_2 )
{
int V_28 ;
V_2 -> V_13 = sizeof( V_2 -> V_11 ) ;
V_2 -> V_28 = F_6 ( V_27 , & V_2 -> V_24 , sizeof( V_2 -> V_24 ) , 0 ,
(struct V_29 * ) V_2 -> V_11 , & V_2 -> V_13 ) ;
if ( V_2 -> V_28 < 0 )
return 0 ;
V_2 -> V_19 = V_27 ;
if ( V_2 -> V_24 . V_30 != V_31 ) {
V_28 = F_7 ( sizeof( V_2 -> V_24 . V_25 ) - 1 ,
strlen ( ( char * ) & V_2 -> V_24 ) ) ;
memmove ( V_2 -> V_24 . V_25 , & V_2 -> V_24 , V_28 ) ;
V_2 -> V_24 . V_25 [ V_28 ] = '\0' ;
V_2 -> V_24 . V_30 = V_31 ;
V_2 -> V_24 . V_32 = 0 ;
V_2 -> V_24 . V_28 = V_28 ;
F_1 ( V_2 , L_1
L_2 ) ;
return 0 ;
}
if ( V_2 -> V_24 . V_28 >= V_33 ) {
F_8 ( V_2 , L_3 , 1 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_24 . V_32 != V_34 ) {
F_8 ( V_2 , L_4
STRING ( V_34 ) L_5 , 1 , 0 ) ;
}
V_2 -> V_24 . V_25 [ V_2 -> V_24 . V_28 ] = '\0' ;
V_2 -> V_21 = F_3 ( V_2 ) ;
if ( V_2 -> V_21 == NULL ) {
F_8 ( V_2 , L_6 , 1 , 0 ) ;
return 0 ;
}
return 1 ;
}
int F_9 ( struct V_1 * V_2 , const char * V_35 , int V_36 ,
int V_37 , int V_38 )
{
struct F_8 V_3 ;
int V_28 , V_39 ;
do {
V_3 . V_37 = V_37 ;
V_37 = 0 ;
V_28 = F_7 ( V_36 , V_33 - 1 ) ;
if ( V_28 == V_36 ) V_3 . V_38 = V_38 ;
else V_3 . V_38 = 1 ;
memcpy ( V_3 . V_25 , V_35 , V_28 ) ;
V_3 . V_25 [ V_28 ] = '\0' ;
V_36 -= V_28 ;
V_35 += V_28 ;
V_3 . V_28 = V_28 + 1 ;
V_28 = sizeof( V_3 ) + V_3 . V_28 - sizeof( V_3 . V_25 ) ;
V_39 = F_10 ( V_2 -> V_19 , & V_3 , V_28 , 0 ,
(struct V_29 * ) V_2 -> V_11 , V_2 -> V_13 ) ;
if ( V_39 < 0 )
return - V_40 ;
} while ( V_36 > 0 );
return 0 ;
}
int F_8 ( struct V_1 * V_2 , const char * V_35 , int V_37 , int V_38 )
{
return F_9 ( V_2 , V_35 , strlen ( V_35 ) , V_37 , V_38 ) ;
}
int F_11 ( void )
{
F_12 ( V_41 ) ;
return 0 ;
}
int F_13 ( char * V_42 , int type , const void * V_25 , int V_28 )
{
struct V_43 V_44 ;
struct F_13 V_45 ;
int V_39 , V_37 = 0 ;
F_14 () ;
if ( V_46 < 0 ) {
V_46 = F_15 ( V_47 , V_48 , 0 ) ;
if ( V_46 < 0 ) {
V_37 = - V_40 ;
F_16 ( V_49 L_7
L_8 , V_40 ) ;
}
}
F_17 () ;
if ( V_37 )
return V_37 ;
V_44 . V_50 = V_51 ;
strcpy ( V_44 . V_52 , V_42 ) ;
V_45 . V_30 = V_31 ;
V_45 . V_32 = V_34 ;
V_45 . type = type ;
V_28 = ( V_28 > sizeof( V_45 . V_25 ) ) ? sizeof( V_45 . V_25 ) : V_28 ;
V_45 . V_28 = V_28 ;
memcpy ( V_45 . V_25 , V_25 , V_28 ) ;
V_37 = 0 ;
V_28 = sizeof( V_45 ) + V_45 . V_28 - sizeof( V_45 . V_25 ) ;
V_39 = F_10 ( V_46 , & V_45 , V_28 , 0 , (struct V_29 * ) & V_44 ,
sizeof( V_44 ) ) ;
if ( V_39 < 0 ) {
V_37 = - V_40 ;
F_16 ( V_49 L_9
L_8 , V_40 ) ;
}
return V_37 ;
}
