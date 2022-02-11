static int F_1 ( char * V_1 , const char * V_2 , T_1 * V_3 ,
T_2 * V_4 , char * * V_5 , char * * V_6 )
{
char * V_7 ;
while ( * V_1 ++ != ' ' )
if ( V_1 > V_2 - 12 )
return - 1 ;
for ( V_7 = V_1 ; V_7 <= V_2 ; V_7 ++ )
if ( * V_7 == '\n' )
break;
if ( V_7 > V_2 || * V_7 != '\n' )
return - 1 ;
* V_5 = V_1 ;
* V_3 = F_2 ( F_3 ( V_1 , & V_1 , 10 ) ) ;
while ( * V_1 == ' ' ) {
if ( V_1 >= V_2 )
return - 1 ;
V_1 ++ ;
}
* V_4 = F_3 ( V_1 , & V_1 , 10 ) ;
* V_6 = V_1 ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 , unsigned int V_10 ,
struct V_11 * V_12 , enum V_13 V_14 )
{
unsigned int V_15 ;
const struct V_16 * V_17 ;
const struct V_18 * V_19 ;
struct V_18 V_20 ;
const char * V_21 ;
char * V_1 , * V_22 ;
int V_23 = F_5 ( V_14 ) ;
struct V_24 * exp ;
struct V_25 * V_26 ;
T_1 V_27 ;
T_2 V_28 ;
T_3 V_4 ;
int V_29 , V_30 = V_31 ;
char * V_32 , * V_33 ;
F_6 (nf_nat_irc_hook) V_34 ;
if ( V_23 == V_35 )
return V_31 ;
if ( V_14 != V_36 && V_14 != V_37 )
return V_31 ;
V_19 = F_7 ( V_9 , V_10 , sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return V_31 ;
V_15 = V_10 + V_19 -> V_38 * 4 ;
if ( V_15 >= V_9 -> V_39 )
return V_31 ;
F_8 ( & V_40 ) ;
V_22 = F_7 ( V_9 , V_15 , V_9 -> V_39 - V_15 ,
V_41 ) ;
F_9 ( V_22 == NULL ) ;
V_1 = V_22 ;
V_21 = V_22 + V_9 -> V_39 - V_15 ;
while ( V_1 < V_21 - ( 19 + V_42 ) ) {
if ( memcmp ( V_1 , L_1 , 5 ) ) {
V_1 ++ ;
continue;
}
V_1 += 5 ;
V_17 = F_10 ( V_9 ) ;
F_11 ( L_2 ,
& V_17 -> V_43 , F_12 ( V_19 -> V_44 ) ,
& V_17 -> V_45 , F_12 ( V_19 -> V_46 ) ) ;
for ( V_29 = 0 ; V_29 < F_13 ( V_47 ) ; V_29 ++ ) {
if ( memcmp ( V_1 , V_47 [ V_29 ] , strlen ( V_47 [ V_29 ] ) ) ) {
continue;
}
V_1 += strlen ( V_47 [ V_29 ] ) ;
F_11 ( L_3 , V_47 [ V_29 ] ) ;
if ( F_1 ( V_1 , V_21 , & V_27 ,
& V_28 , & V_32 , & V_33 ) ) {
F_11 ( L_4 ) ;
continue;
}
F_11 ( L_5 ,
& V_27 , V_28 ) ;
V_26 = & V_12 -> V_48 [ V_23 ] . V_26 ;
if ( V_26 -> V_49 . V_50 . V_3 != V_27 &&
V_26 -> V_51 . V_50 . V_3 != V_27 ) {
F_14 ( L_6 ,
& V_26 -> V_49 . V_50 . V_3 ,
& V_27 , V_28 ) ;
continue;
}
exp = F_15 ( V_12 ) ;
if ( exp == NULL ) {
V_30 = V_52 ;
goto V_53;
}
V_26 = & V_12 -> V_48 [ ! V_23 ] . V_26 ;
V_4 = F_16 ( V_28 ) ;
F_17 ( exp , V_54 ,
V_26 -> V_49 . V_55 ,
NULL , & V_26 -> V_51 . V_50 ,
V_56 , NULL , & V_4 ) ;
V_34 = F_18 ( V_57 ) ;
if ( V_34 && V_12 -> V_58 & V_59 )
V_30 = V_34 ( V_9 , V_14 , V_10 ,
V_32 - V_22 ,
V_33 - V_32 ,
exp ) ;
else if ( F_19 ( exp ) != 0 )
V_30 = V_52 ;
F_20 ( exp ) ;
goto V_53;
}
}
V_53:
F_21 ( & V_40 ) ;
return V_30 ;
}
static int T_4 F_22 ( void )
{
int V_29 , V_30 ;
if ( V_60 < 1 ) {
F_23 ( V_61 L_7 ) ;
return - V_62 ;
}
V_63 . V_64 = V_60 ;
V_63 . V_65 = V_66 ;
V_41 = F_24 ( 65536 , V_67 ) ;
if ( ! V_41 )
return - V_68 ;
if ( V_69 == 0 )
V_70 [ V_69 ++ ] = V_71 ;
for ( V_29 = 0 ; V_29 < V_69 ; V_29 ++ ) {
V_72 [ V_29 ] . V_26 . V_49 . V_55 = V_73 ;
V_72 [ V_29 ] . V_26 . V_49 . V_74 . V_75 . V_4 = F_16 ( V_70 [ V_29 ] ) ;
V_72 [ V_29 ] . V_26 . V_51 . V_76 = V_56 ;
V_72 [ V_29 ] . V_77 = & V_63 ;
V_72 [ V_29 ] . V_78 = V_79 ;
V_72 [ V_29 ] . F_4 = F_4 ;
if ( V_70 [ V_29 ] == V_71 )
sprintf ( V_72 [ V_29 ] . V_80 , L_8 ) ;
else
sprintf ( V_72 [ V_29 ] . V_80 , L_9 , V_29 ) ;
V_30 = F_25 ( & V_72 [ V_29 ] ) ;
if ( V_30 ) {
F_23 ( V_61 L_10
L_11 ,
V_72 [ V_29 ] . V_26 . V_49 . V_55 , V_70 [ V_29 ] ) ;
F_26 () ;
return V_30 ;
}
}
return 0 ;
}
static void F_26 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_69 ; V_29 ++ )
F_27 ( & V_72 [ V_29 ] ) ;
F_28 ( V_41 ) ;
}
