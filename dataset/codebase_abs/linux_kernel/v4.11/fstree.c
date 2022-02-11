static struct V_1 * F_1 ( const char * V_2 )
{
T_1 * V_3 ;
struct V_4 * V_5 ;
struct V_6 V_7 ;
struct V_1 * V_8 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
F_3 ( L_1 , V_2 , strerror ( V_9 ) ) ;
V_8 = F_4 ( NULL , NULL ) ;
while ( ( V_5 = F_5 ( V_3 ) ) != NULL ) {
char * V_10 ;
if ( F_6 ( V_5 -> V_11 , L_2 )
|| F_6 ( V_5 -> V_11 , L_3 ) )
continue;
V_10 = F_7 ( V_2 , V_5 -> V_11 ) ;
if ( F_8 ( V_10 , & V_7 ) < 0 )
F_3 ( L_4 , V_10 , strerror ( V_9 ) ) ;
if ( F_9 ( V_7 . V_12 ) ) {
struct V_13 * V_14 ;
T_2 * V_15 ;
V_15 = fopen ( V_10 , L_5 ) ;
if ( ! V_15 ) {
fprintf ( V_16 ,
L_6 ,
V_10 , strerror ( V_9 ) ) ;
} else {
V_14 = F_10 ( F_11 ( V_5 -> V_11 ) ,
F_12 ( V_15 ,
V_7 . V_17 ) ) ;
F_13 ( V_8 , V_14 ) ;
fclose ( V_15 ) ;
}
} else if ( F_14 ( V_7 . V_12 ) ) {
struct V_1 * V_18 ;
V_18 = F_1 ( V_10 ) ;
V_18 = F_15 ( V_18 , F_11 ( V_5 -> V_11 ) ) ;
F_16 ( V_8 , V_18 ) ;
}
free ( V_10 ) ;
}
F_17 ( V_3 ) ;
return V_8 ;
}
struct V_19 * F_18 ( const char * V_2 )
{
struct V_1 * V_8 ;
V_8 = F_1 ( V_2 ) ;
V_8 = F_15 ( V_8 , L_7 ) ;
return F_19 ( V_20 , NULL , V_8 , F_20 ( V_8 ) ) ;
}
