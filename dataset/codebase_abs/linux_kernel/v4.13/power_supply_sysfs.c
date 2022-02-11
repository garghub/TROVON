static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
T_1 V_6 = 0 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
const T_2 V_9 = V_4 - V_10 ;
union V_11 V_12 ;
if ( V_9 == V_13 ) {
V_12 . V_14 = V_8 -> V_15 -> type ;
} else {
V_6 = F_3 ( V_8 , V_9 , & V_12 ) ;
if ( V_6 < 0 ) {
if ( V_6 == - V_16 )
F_4 ( V_2 , L_1 ,
V_4 -> V_4 . V_17 ) ;
else if ( V_6 != - V_18 && V_6 != - V_19 )
F_5 ( V_2 , L_2 ,
V_4 -> V_4 . V_17 , V_6 ) ;
return V_6 ;
}
}
if ( V_9 == V_20 )
return sprintf ( V_5 , L_3 ,
V_21 [ V_12 . V_14 ] ) ;
else if ( V_9 == V_22 )
return sprintf ( V_5 , L_3 ,
V_23 [ V_12 . V_14 ] ) ;
else if ( V_9 == V_24 )
return sprintf ( V_5 , L_3 ,
V_25 [ V_12 . V_14 ] ) ;
else if ( V_9 == V_26 )
return sprintf ( V_5 , L_3 ,
V_27 [ V_12 . V_14 ] ) ;
else if ( V_9 == V_28 )
return sprintf ( V_5 , L_3 ,
V_29 [ V_12 . V_14 ] ) ;
else if ( V_9 == V_13 )
return sprintf ( V_5 , L_3 ,
V_30 [ V_12 . V_14 ] ) ;
else if ( V_9 == V_31 )
return sprintf ( V_5 , L_3 ,
V_32 [ V_12 . V_14 ] ) ;
else if ( V_9 >= V_33 )
return sprintf ( V_5 , L_3 , V_12 . V_34 ) ;
return sprintf ( V_5 , L_4 , V_12 . V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_35 ) {
T_1 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
const T_2 V_9 = V_4 - V_10 ;
union V_11 V_12 ;
switch ( V_9 ) {
case V_20 :
V_6 = F_7 ( V_21 , V_5 ) ;
break;
case V_22 :
V_6 = F_7 ( V_23 , V_5 ) ;
break;
case V_24 :
V_6 = F_7 ( V_25 , V_5 ) ;
break;
case V_26 :
V_6 = F_7 ( V_27 , V_5 ) ;
break;
case V_28 :
V_6 = F_7 ( V_29 , V_5 ) ;
break;
case V_31 :
V_6 = F_7 ( V_32 , V_5 ) ;
break;
default:
V_6 = - V_36 ;
}
if ( V_6 < 0 ) {
long V_37 ;
V_6 = F_8 ( V_5 , 10 , & V_37 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = V_37 ;
}
V_12 . V_14 = V_6 ;
V_6 = F_9 ( V_8 , V_9 , & V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_35 ;
}
static T_4 F_10 ( struct V_38 * V_39 ,
struct V_40 * V_4 ,
int V_41 )
{
struct V_1 * V_2 = F_11 ( V_39 , struct V_1 , V_39 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_4 V_42 = V_43 | V_44 | V_45 ;
int V_46 ;
if ( V_41 == V_13 )
return V_42 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_15 -> V_47 ; V_46 ++ ) {
int V_48 = V_8 -> V_15 -> V_49 [ V_46 ] ;
if ( V_48 == V_41 ) {
if ( V_8 -> V_15 -> V_50 &&
V_8 -> V_15 -> V_50 ( V_8 , V_48 ) > 0 )
V_42 |= V_51 ;
return V_42 ;
}
}
return 0 ;
}
void F_12 ( struct V_52 * V_53 )
{
int V_46 ;
V_53 -> V_54 = V_55 ;
for ( V_46 = 0 ; V_46 < F_13 ( V_10 ) ; V_46 ++ )
V_56 [ V_46 ] = & V_10 [ V_46 ] . V_4 ;
}
static char * F_14 ( const char * V_57 , T_5 V_58 )
{
char * V_6 , * V_59 ;
V_59 = V_6 = F_15 ( strlen ( V_57 ) + 1 , V_58 ) ;
if ( ! V_6 )
return NULL ;
while ( * V_57 )
* V_59 ++ = toupper ( * V_57 ++ ) ;
* V_59 = 0 ;
return V_6 ;
}
int F_16 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_6 = 0 , V_62 ;
char * V_63 ;
char * V_64 ;
F_4 ( V_2 , L_5 ) ;
if ( ! V_8 || ! V_8 -> V_15 ) {
F_4 ( V_2 , L_6 ) ;
return V_6 ;
}
F_4 ( V_2 , L_7 , V_8 -> V_15 -> V_17 ) ;
V_6 = F_17 ( V_61 , L_8 , V_8 -> V_15 -> V_17 ) ;
if ( V_6 )
return V_6 ;
V_63 = ( char * ) F_18 ( V_65 ) ;
if ( ! V_63 )
return - V_66 ;
for ( V_62 = 0 ; V_62 < V_8 -> V_15 -> V_47 ; V_62 ++ ) {
struct V_3 * V_4 ;
char * line ;
V_4 = & V_10 [ V_8 -> V_15 -> V_49 [ V_62 ] ] ;
V_6 = F_1 ( V_2 , V_4 , V_63 ) ;
if ( V_6 == - V_18 || V_6 == - V_16 ) {
V_6 = 0 ;
continue;
}
if ( V_6 < 0 )
goto V_67;
line = strchr ( V_63 , '\n' ) ;
if ( line )
* line = 0 ;
V_64 = F_14 ( V_4 -> V_4 . V_17 , V_65 ) ;
if ( ! V_64 ) {
V_6 = - V_66 ;
goto V_67;
}
F_4 ( V_2 , L_9 , V_64 , V_63 ) ;
V_6 = F_17 ( V_61 , L_10 , V_64 , V_63 ) ;
F_19 ( V_64 ) ;
if ( V_6 )
goto V_67;
}
V_67:
F_20 ( ( unsigned long ) V_63 ) ;
return V_6 ;
}
