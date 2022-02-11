static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
static char * V_6 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 ,
L_6 , L_7 , L_8 , L_9 ,
L_10 , L_11
} ;
static char * V_7 [] = {
L_1 , L_12 , L_13 , L_14 , L_15
} ;
static char * V_8 [] = {
L_1 , L_16 , L_17 , L_18
} ;
static char * V_9 [] = {
L_1 , L_19 , L_20 , L_21 , L_22 ,
L_23 , L_24 , L_25 ,
L_26
} ;
static char * V_10 [] = {
L_1 , L_27 , L_28 , L_29 , L_30 , L_31 ,
L_32
} ;
static char * V_11 [] = {
L_1 , L_33 , L_34 , L_35 , L_36 , L_15
} ;
static char * V_12 [] = {
L_1 , L_37 , L_38
} ;
T_1 V_13 = 0 ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
const T_2 V_16 = V_4 - V_17 ;
union V_18 V_19 ;
if ( V_16 == V_20 ) {
V_19 . V_21 = V_15 -> V_22 -> type ;
} else {
V_13 = F_3 ( V_15 , V_16 , & V_19 ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_23 )
F_4 ( V_2 , L_39 ,
V_4 -> V_4 . V_24 ) ;
else if ( V_13 != - V_25 && V_13 != - V_26 )
F_5 ( V_2 , L_40 ,
V_4 -> V_4 . V_24 , V_13 ) ;
return V_13 ;
}
}
if ( V_16 == V_27 )
return sprintf ( V_5 , L_41 , V_7 [ V_19 . V_21 ] ) ;
else if ( V_16 == V_28 )
return sprintf ( V_5 , L_41 , V_8 [ V_19 . V_21 ] ) ;
else if ( V_16 == V_29 )
return sprintf ( V_5 , L_41 , V_9 [ V_19 . V_21 ] ) ;
else if ( V_16 == V_30 )
return sprintf ( V_5 , L_41 , V_10 [ V_19 . V_21 ] ) ;
else if ( V_16 == V_31 )
return sprintf ( V_5 , L_41 , V_11 [ V_19 . V_21 ] ) ;
else if ( V_16 == V_20 )
return sprintf ( V_5 , L_41 , V_6 [ V_19 . V_21 ] ) ;
else if ( V_16 == V_32 )
return sprintf ( V_5 , L_41 , V_12 [ V_19 . V_21 ] ) ;
else if ( V_16 >= V_33 )
return sprintf ( V_5 , L_41 , V_19 . V_34 ) ;
return sprintf ( V_5 , L_42 , V_19 . V_21 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_35 ) {
T_1 V_13 ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
const T_2 V_16 = V_4 - V_17 ;
union V_18 V_19 ;
long V_36 ;
V_13 = F_7 ( V_5 , 10 , & V_36 ) ;
if ( V_13 < 0 )
return V_13 ;
V_19 . V_21 = V_36 ;
V_13 = F_8 ( V_15 , V_16 , & V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_35 ;
}
static T_4 F_9 ( struct V_37 * V_38 ,
struct V_39 * V_4 ,
int V_40 )
{
struct V_1 * V_2 = F_10 ( V_38 , struct V_1 , V_38 ) ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
T_4 V_41 = V_42 | V_43 | V_44 ;
int V_45 ;
if ( V_40 == V_20 )
return V_41 ;
for ( V_45 = 0 ; V_45 < V_15 -> V_22 -> V_46 ; V_45 ++ ) {
int V_47 = V_15 -> V_22 -> V_48 [ V_45 ] ;
if ( V_47 == V_40 ) {
if ( V_15 -> V_22 -> V_49 &&
V_15 -> V_22 -> V_49 ( V_15 , V_47 ) > 0 )
V_41 |= V_50 ;
return V_41 ;
}
}
return 0 ;
}
void F_11 ( struct V_51 * V_52 )
{
int V_45 ;
V_52 -> V_53 = V_54 ;
for ( V_45 = 0 ; V_45 < F_12 ( V_17 ) ; V_45 ++ )
V_55 [ V_45 ] = & V_17 [ V_45 ] . V_4 ;
}
static char * F_13 ( const char * V_56 , T_5 V_57 )
{
char * V_13 , * V_58 ;
V_58 = V_13 = F_14 ( strlen ( V_56 ) + 1 , V_57 ) ;
if ( ! V_13 )
return NULL ;
while ( * V_56 )
* V_58 ++ = toupper ( * V_56 ++ ) ;
* V_58 = 0 ;
return V_13 ;
}
int F_15 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_14 * V_15 = F_2 ( V_2 ) ;
int V_13 = 0 , V_61 ;
char * V_62 ;
char * V_63 ;
F_4 ( V_2 , L_43 ) ;
if ( ! V_15 || ! V_15 -> V_22 ) {
F_4 ( V_2 , L_44 ) ;
return V_13 ;
}
F_4 ( V_2 , L_45 , V_15 -> V_22 -> V_24 ) ;
V_13 = F_16 ( V_60 , L_46 , V_15 -> V_22 -> V_24 ) ;
if ( V_13 )
return V_13 ;
V_62 = ( char * ) F_17 ( V_64 ) ;
if ( ! V_62 )
return - V_65 ;
for ( V_61 = 0 ; V_61 < V_15 -> V_22 -> V_46 ; V_61 ++ ) {
struct V_3 * V_4 ;
char * line ;
V_4 = & V_17 [ V_15 -> V_22 -> V_48 [ V_61 ] ] ;
V_13 = F_1 ( V_2 , V_4 , V_62 ) ;
if ( V_13 == - V_25 || V_13 == - V_23 ) {
V_13 = 0 ;
continue;
}
if ( V_13 < 0 )
goto V_66;
line = strchr ( V_62 , '\n' ) ;
if ( line )
* line = 0 ;
V_63 = F_13 ( V_4 -> V_4 . V_24 , V_64 ) ;
if ( ! V_63 ) {
V_13 = - V_65 ;
goto V_66;
}
F_4 ( V_2 , L_47 , V_63 , V_62 ) ;
V_13 = F_16 ( V_60 , L_48 , V_63 , V_62 ) ;
F_18 ( V_63 ) ;
if ( V_13 )
goto V_66;
}
V_66:
F_19 ( ( unsigned long ) V_62 ) ;
return V_13 ;
}
