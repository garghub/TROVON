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
char * tmpnam ;
if ( F_6 ( V_5 -> V_10 , L_2 )
|| F_6 ( V_5 -> V_10 , L_3 ) )
continue;
tmpnam = F_7 ( V_2 , V_5 -> V_10 ) ;
if ( F_8 ( tmpnam , & V_7 ) < 0 )
F_3 ( L_4 , tmpnam , strerror ( V_9 ) ) ;
if ( F_9 ( V_7 . V_11 ) ) {
struct V_12 * V_13 ;
T_2 * V_14 ;
V_14 = fopen ( tmpnam , L_5 ) ;
if ( ! V_14 ) {
fprintf ( V_15 ,
L_6 ,
tmpnam , strerror ( V_9 ) ) ;
} else {
V_13 = F_10 ( F_11 ( V_5 -> V_10 ) ,
F_12 ( V_14 ,
V_7 . V_16 ) ) ;
F_13 ( V_8 , V_13 ) ;
fclose ( V_14 ) ;
}
} else if ( F_14 ( V_7 . V_11 ) ) {
struct V_1 * V_17 ;
V_17 = F_1 ( tmpnam ) ;
V_17 = F_15 ( V_17 , F_11 ( V_5 -> V_10 ) ) ;
F_16 ( V_8 , V_17 ) ;
}
free ( tmpnam ) ;
}
F_17 ( V_3 ) ;
return V_8 ;
}
struct V_18 * F_18 ( const char * V_2 )
{
struct V_1 * V_8 ;
V_8 = F_1 ( V_2 ) ;
V_8 = F_15 ( V_8 , L_7 ) ;
return F_19 ( NULL , V_8 , F_20 ( V_8 ) ) ;
}
