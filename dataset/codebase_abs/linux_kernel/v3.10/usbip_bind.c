void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 )
{
char V_3 [] = L_2 ;
char V_4 [] = L_3 ;
char V_5 [ V_6 ] ;
char V_7 [ V_6 ] ;
char V_8 [ V_9 ] ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_12 * V_14 ;
struct V_12 * V_15 ;
int V_16 , V_17 = 0 ;
int V_18 , V_19 = - 1 ;
V_18 = F_3 ( V_5 , V_6 ) ;
if ( V_18 < 0 ) {
F_4 ( L_4 , strerror ( V_20 ) ) ;
return - 1 ;
}
snprintf ( V_7 , sizeof( V_7 ) , L_5 ,
V_5 , V_21 , V_3 , V_22 ,
V_23 , V_4 ) ;
V_13 = F_5 ( V_7 ) ;
if ( ! V_13 ) {
F_6 ( L_6 , strerror ( V_20 ) ) ;
return - 1 ;
}
V_11 = F_7 ( V_3 , V_2 ) ;
if ( ! V_11 ) {
F_6 ( L_7 , V_2 , strerror ( V_20 ) ) ;
goto V_24;
}
V_14 = F_8 ( V_11 , L_8 ) ;
V_15 = F_8 ( V_11 , L_9 ) ;
if ( ! V_14 || ! V_15 ) {
F_6 ( L_10 ,
strerror ( V_20 ) ) ;
goto V_25;
}
for ( V_16 = 0 ; V_16 < atoi ( V_15 -> V_26 ) ; V_16 ++ ) {
snprintf ( V_8 , V_9 , L_11 , V_2 ,
V_14 -> V_26 , V_16 ) ;
V_18 = F_9 ( V_13 , V_8 ,
V_9 ) ;
if ( V_18 < 0 ) {
F_6 ( L_12 , V_8 ) ;
V_17 = 1 ;
}
}
if ( ! V_17 )
V_19 = 0 ;
V_25:
F_10 ( V_11 ) ;
V_24:
F_11 ( V_13 ) ;
return V_19 ;
}
static int F_12 ( char * V_2 )
{
char V_3 [] = L_2 ;
char V_8 [ V_9 ] ;
struct V_10 * V_11 ;
struct V_10 * V_27 ;
struct V_28 * V_29 ;
struct V_12 * V_30 ;
struct V_12 * V_14 ;
struct V_12 * V_31 ;
struct V_12 * V_15 ;
int V_16 , V_18 ;
enum V_32 V_33 = V_34 ;
V_11 = F_7 ( V_3 , V_2 ) ;
if ( ! V_11 ) {
F_6 ( L_7 , V_2 , strerror ( V_20 ) ) ;
return - 1 ;
}
V_14 = F_8 ( V_11 , L_8 ) ;
V_31 = F_8 ( V_11 , L_13 ) ;
V_15 = F_8 ( V_11 , L_9 ) ;
if ( ! V_14 || ! V_31 || ! V_15 ) {
F_6 ( L_10 ,
strerror ( V_20 ) ) ;
goto V_25;
}
if ( ! strncmp ( V_31 -> V_26 , L_14 , V_31 -> V_35 ) ) {
F_6 ( L_15 ) ;
goto V_25;
}
for ( V_16 = 0 ; V_16 < atoi ( V_15 -> V_26 ) ; V_16 ++ ) {
snprintf ( V_8 , V_9 , L_11 , V_2 ,
V_14 -> V_26 , V_16 ) ;
V_27 = F_7 ( V_3 , V_8 ) ;
if ( ! V_27 ) {
F_6 ( L_16 ,
strerror ( V_20 ) ) ;
goto V_25;
}
F_6 ( L_17 , V_27 -> V_36 , V_27 -> V_37 ) ;
if ( ! strncmp ( L_18 , V_27 -> V_37 , V_38 ) )
continue;
if ( ! strncmp ( V_23 , V_27 -> V_37 ,
V_38 ) ) {
V_33 = V_39 ;
continue;
}
V_29 = F_13 ( V_3 , V_27 -> V_37 ) ;
if ( ! V_29 ) {
F_6 ( L_19 ,
V_27 -> V_36 , strerror ( V_20 ) ) ;
goto V_40;
}
V_30 = F_14 ( V_29 , L_20 ) ;
if ( ! V_30 ) {
F_6 ( L_21 ,
strerror ( V_20 ) ) ;
goto V_41;
}
V_18 = F_9 ( V_30 , V_27 -> V_42 ,
V_9 ) ;
if ( V_18 < 0 ) {
F_6 ( L_22 , V_27 -> V_42 ) ;
V_33 = V_43 ;
}
F_15 ( V_29 ) ;
F_10 ( V_27 ) ;
}
goto V_44;
V_41:
F_15 ( V_29 ) ;
V_40:
F_10 ( V_27 ) ;
V_25:
V_33 = V_43 ;
V_44:
F_10 ( V_11 ) ;
return V_33 ;
}
static int F_16 ( char * V_2 )
{
int V_18 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 == V_43 ) {
F_4 ( L_23 , V_2 ) ;
return - 1 ;
} else if ( V_18 == V_39 ) {
F_4 ( L_24 , V_2 ,
V_23 ) ;
return - 1 ;
}
V_18 = F_17 ( V_2 , 1 ) ;
if ( V_18 < 0 ) {
F_4 ( L_25 , V_2 ) ;
return - 1 ;
}
V_18 = F_2 ( V_2 ) ;
if ( V_18 < 0 ) {
F_4 ( L_26 , V_23 ) ;
F_17 ( V_2 , 0 ) ;
return - 1 ;
}
printf ( L_27 , V_2 ) ;
return 0 ;
}
int F_18 ( int V_45 , char * V_46 [] )
{
static const struct V_47 V_48 [] = {
{ L_28 , V_49 , NULL , 'b' } ,
{ NULL , 0 , NULL , 0 }
} ;
int V_50 ;
int V_19 = - 1 ;
for (; ; ) {
V_50 = F_19 ( V_45 , V_46 , L_29 , V_48 , NULL ) ;
if ( V_50 == - 1 )
break;
switch ( V_50 ) {
case 'b' :
V_19 = F_16 ( V_51 ) ;
goto V_44;
default:
goto V_52;
}
}
V_52:
F_1 () ;
V_44:
return V_19 ;
}
