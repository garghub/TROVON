static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
static char * V_6 [] = {
L_1 , L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7
} ;
static char * V_7 [] = {
L_8 , L_9 , L_10 , L_11 , L_12
} ;
static char * V_8 [] = {
L_8 , L_13 , L_14 , L_15
} ;
static char * V_9 [] = {
L_8 , L_16 , L_17 , L_18 , L_19 ,
L_20 , L_21 ,
} ;
static char * V_10 [] = {
L_8 , L_22 , L_23 , L_24 , L_25 , L_26 ,
L_27
} ;
static char * V_11 [] = {
L_8 , L_28 , L_29 , L_30 , L_31 , L_12
} ;
T_1 V_12 = 0 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const T_2 V_15 = V_4 - V_16 ;
union V_17 V_18 ;
if ( V_15 == V_19 )
V_18 . V_20 = V_14 -> type ;
else
V_12 = V_14 -> V_21 ( V_14 , V_15 , & V_18 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_22 )
F_3 ( V_2 , L_32 ,
V_4 -> V_4 . V_23 ) ;
else if ( V_12 != - V_24 )
F_4 ( V_2 , L_33 ,
V_4 -> V_4 . V_23 ) ;
return V_12 ;
}
if ( V_15 == V_25 )
return sprintf ( V_5 , L_34 , V_7 [ V_18 . V_20 ] ) ;
else if ( V_15 == V_26 )
return sprintf ( V_5 , L_34 , V_8 [ V_18 . V_20 ] ) ;
else if ( V_15 == V_27 )
return sprintf ( V_5 , L_34 , V_9 [ V_18 . V_20 ] ) ;
else if ( V_15 == V_28 )
return sprintf ( V_5 , L_34 , V_10 [ V_18 . V_20 ] ) ;
else if ( V_15 == V_29 )
return sprintf ( V_5 , L_34 , V_11 [ V_18 . V_20 ] ) ;
else if ( V_15 == V_19 )
return sprintf ( V_5 , L_34 , V_6 [ V_18 . V_20 ] ) ;
else if ( V_15 >= V_30 )
return sprintf ( V_5 , L_34 , V_18 . V_31 ) ;
return sprintf ( V_5 , L_35 , V_18 . V_20 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_32 ) {
T_1 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const T_2 V_15 = V_4 - V_16 ;
union V_17 V_18 ;
long V_33 ;
V_12 = F_6 ( V_5 , 10 , & V_33 ) ;
if ( V_12 < 0 )
return V_12 ;
V_18 . V_20 = V_33 ;
V_12 = V_14 -> V_34 ( V_14 , V_15 , & V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_32 ;
}
static T_4 F_7 ( struct V_35 * V_36 ,
struct V_37 * V_4 ,
int V_38 )
{
struct V_1 * V_2 = F_8 ( V_36 , struct V_1 , V_36 ) ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
T_4 V_39 = V_40 | V_41 | V_42 ;
int V_43 ;
if ( V_38 == V_19 )
return V_39 ;
for ( V_43 = 0 ; V_43 < V_14 -> V_44 ; V_43 ++ ) {
int V_45 = V_14 -> V_46 [ V_43 ] ;
if ( V_45 == V_38 ) {
if ( V_14 -> V_47 &&
V_14 -> V_47 ( V_14 , V_45 ) > 0 )
V_39 |= V_48 ;
return V_39 ;
}
}
return 0 ;
}
void F_9 ( struct V_49 * V_50 )
{
int V_43 ;
V_50 -> V_51 = V_52 ;
for ( V_43 = 0 ; V_43 < F_10 ( V_16 ) ; V_43 ++ )
V_53 [ V_43 ] = & V_16 [ V_43 ] . V_4 ;
}
static char * F_11 ( const char * V_54 , T_5 V_55 )
{
char * V_12 , * V_56 ;
V_56 = V_12 = F_12 ( strlen ( V_54 ) + 1 , V_55 ) ;
if ( ! V_12 )
return NULL ;
while ( * V_54 )
* V_56 ++ = toupper ( * V_54 ++ ) ;
* V_56 = 0 ;
return V_12 ;
}
int F_13 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
int V_12 = 0 , V_59 ;
char * V_60 ;
char * V_61 ;
F_3 ( V_2 , L_36 ) ;
if ( ! V_14 || ! V_14 -> V_2 ) {
F_3 ( V_2 , L_37 ) ;
return V_12 ;
}
F_3 ( V_2 , L_38 , V_14 -> V_23 ) ;
V_12 = F_14 ( V_58 , L_39 , V_14 -> V_23 ) ;
if ( V_12 )
return V_12 ;
V_60 = ( char * ) F_15 ( V_62 ) ;
if ( ! V_60 )
return - V_63 ;
for ( V_59 = 0 ; V_59 < V_14 -> V_44 ; V_59 ++ ) {
struct V_3 * V_4 ;
char * line ;
V_4 = & V_16 [ V_14 -> V_46 [ V_59 ] ] ;
V_12 = F_1 ( V_2 , V_4 , V_60 ) ;
if ( V_12 == - V_24 || V_12 == - V_22 ) {
V_12 = 0 ;
continue;
}
if ( V_12 < 0 )
goto V_64;
line = strchr ( V_60 , '\n' ) ;
if ( line )
* line = 0 ;
V_61 = F_11 ( V_4 -> V_4 . V_23 , V_62 ) ;
if ( ! V_61 ) {
V_12 = - V_63 ;
goto V_64;
}
F_3 ( V_2 , L_40 , V_61 , V_60 ) ;
V_12 = F_14 ( V_58 , L_41 , V_61 , V_60 ) ;
F_16 ( V_61 ) ;
if ( V_12 )
goto V_64;
}
V_64:
F_17 ( ( unsigned long ) V_60 ) ;
return V_12 ;
}
