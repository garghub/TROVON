static struct V_1 * T_1
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 )
{
if ( ! strcmp ( V_6 , L_1 ) ) {
return F_2 ( NULL , L_1 ,
F_3 ( V_3 , 0 ) , 0 ,
V_7 [ V_8 ] . V_9 , 1 ) ;
} else if ( ! strcmp ( V_6 , L_2 ) ) {
return F_2 ( NULL , L_2 ,
F_3 ( V_3 , 0 ) , 0 ,
V_7 [ V_8 ] . V_10 , 1 ) ;
} else {
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_12 ) ; V_11 ++ ) {
if ( ! strcmp ( V_6 , V_12 [ V_11 ] . V_6 ) ) {
return F_2 ( NULL ,
V_12 [ V_11 ] . V_6 ,
L_1 , 0 , 1 ,
V_12 [ V_11 ] . div [ V_13 ] ) ;
}
}
}
return F_5 ( - V_14 ) ;
}
static void T_1 F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * * V_15 ;
unsigned int V_11 ;
int V_16 ;
T_2 V_17 ;
if ( F_7 ( & V_17 ) )
return;
F_8 ( ! ( V_17 & F_9 ( 19 ) ) ) ;
V_8 = ( ! ! ( V_17 & F_9 ( 18 ) ) << 2 ) |
( ! ! ( V_17 & F_9 ( 12 ) ) << 1 ) |
( ! ! ( V_17 & F_9 ( 11 ) ) ) ;
V_13 = ( ! ! ( V_17 & F_9 ( 2 ) ) << 1 ) |
( ! ! ( V_17 & F_9 ( 1 ) ) ) ;
V_16 = F_10 ( V_3 , L_3 ) ;
if ( V_16 < 0 ) {
F_11 ( L_4 , V_18 ) ;
return;
}
V_5 = F_12 ( sizeof( * V_5 ) , V_19 ) ;
V_15 = F_13 ( V_16 , sizeof( * V_15 ) , V_19 ) ;
if ( V_5 == NULL || V_15 == NULL ) {
return;
}
F_14 ( & V_5 -> V_20 ) ;
V_5 -> V_21 . V_15 = V_15 ;
V_5 -> V_21 . V_22 = V_16 ;
V_5 -> V_23 = F_15 ( V_3 , 0 ) ;
if ( F_16 ( V_5 -> V_23 == NULL ) )
return;
for ( V_11 = 0 ; V_11 < V_16 ; ++ V_11 ) {
const char * V_6 ;
struct V_1 * V_1 ;
F_17 ( V_3 , L_3 , V_11 ,
& V_6 ) ;
V_1 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( F_18 ( V_1 ) )
F_11 ( L_5 ,
V_18 , V_3 -> V_6 , V_6 , F_19 ( V_1 ) ) ;
else
V_5 -> V_21 . V_15 [ V_11 ] = V_1 ;
}
F_20 ( V_3 , V_24 , & V_5 -> V_21 ) ;
F_21 ( V_3 ) ;
}
