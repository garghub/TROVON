static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 , V_10 ;
T_1 * V_11 ;
char V_12 ;
int V_13 , V_14 ;
V_14 = F_2 ( V_6 ,
V_15 ,
& V_10 ) ;
if ( V_14 < 0 )
return;
F_3 ( V_4 , L_1 ) ;
F_3 ( V_4 , L_2 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
V_11 = V_6 -> V_17 [ V_13 ] ;
if ( V_11 == NULL )
continue;
V_14 = F_4 ( V_11 , & V_9 ) ;
if ( V_14 < 0 )
continue;
if ( memcmp ( & V_9 , & V_10 , sizeof( V_10 ) ) == 0 )
V_12 = '*' ;
else
V_12 = ' ' ;
F_3 ( V_4 , L_3 , V_12 ,
V_9 . V_18 , V_9 . V_19 , V_9 . V_20 ) ;
}
if ( ! V_6 -> V_21 )
return;
V_14 = F_2 ( V_6 ,
V_22 ,
& V_10 ) ;
if ( V_14 < 0 )
return;
F_3 ( V_4 , L_4 ) ;
F_3 ( V_4 , L_2 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
V_11 = V_6 -> V_23 [ V_13 ] ;
if ( V_11 == NULL )
continue;
V_14 = F_4 ( V_11 , & V_9 ) ;
if ( V_14 < 0 )
continue;
if ( memcmp ( & V_9 , & V_10 , sizeof( V_10 ) ) == 0 )
V_12 = '*' ;
else
V_12 = ' ' ;
F_3 ( V_4 , L_3 , V_12 ,
V_9 . V_18 , V_9 . V_19 , V_9 . V_20 ) ;
}
}
static void F_5 ( struct V_5 * V_6 , struct V_1 * V_24 ,
const char * V_25 ,
void (* F_6)( struct V_1 * V_26 ,
struct V_3 * V_27 ) )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_6 -> V_28 , V_25 , V_24 ) ;
if ( V_2 == NULL )
return;
F_8 ( V_2 , V_6 , F_6 ) ;
if ( F_9 ( V_2 ) < 0 )
F_10 ( V_2 ) ;
}
void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_24 ;
V_24 = F_7 ( V_6 -> V_28 , L_5 ,
V_6 -> V_28 -> V_29 ) ;
if ( V_24 == NULL )
return;
V_24 -> V_30 = V_31 | V_32 | V_33 ;
if ( F_9 ( V_24 ) < 0 ) {
F_10 ( V_24 ) ;
return;
}
F_5 ( V_6 , V_24 , L_6 , F_1 ) ;
}
