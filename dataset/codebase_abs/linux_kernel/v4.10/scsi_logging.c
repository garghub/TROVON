static char * F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
unsigned long V_4 = sizeof( V_3 -> V_5 ) / V_6 ;
unsigned long V_7 = 0 ;
F_2 () ;
V_3 = F_3 ( & V_8 ) ;
V_7 = F_4 ( & V_3 -> V_9 , V_4 ) ;
if ( F_5 ( V_7 < V_4 ) ) {
while ( F_6 ( V_7 , & V_3 -> V_9 ) ) {
V_7 = F_7 ( & V_3 -> V_9 , V_4 , V_7 ) ;
if ( V_7 >= V_4 )
break;
}
}
if ( F_8 ( V_7 >= V_4 ) ) {
F_9 () ;
return NULL ;
}
* V_1 = V_6 ;
return V_3 -> V_5 + V_7 * V_6 ;
}
static void F_10 ( char * V_10 )
{
struct V_2 * V_3 ;
unsigned long V_7 ;
int V_11 ;
V_3 = F_3 ( & V_8 ) ;
if ( V_10 >= V_3 -> V_5 &&
V_10 < V_3 -> V_5 + V_12 ) {
V_7 = ( V_10 - V_3 -> V_5 ) / V_6 ;
V_11 = F_11 ( V_7 , & V_3 -> V_9 ) ;
F_8 ( ! V_11 ) ;
}
F_9 () ;
}
static inline const char * F_12 ( const struct V_13 * V_14 )
{
return V_14 -> V_15 -> V_16 ?
V_14 -> V_15 -> V_16 -> V_17 : NULL ;
}
static T_1 F_13 ( char * V_18 , T_1 V_19 ,
const char * V_20 , int V_21 )
{
T_1 V_22 = 0 ;
if ( V_20 )
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_1 , V_20 ) ;
if ( F_8 ( V_22 >= V_19 ) )
return V_22 ;
if ( V_21 >= 0 )
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_2 , V_21 ) ;
return V_22 ;
}
void F_15 ( const char * V_23 , const struct V_24 * V_25 ,
const char * V_20 , const char * V_26 , ... )
{
T_2 args ;
char * V_18 ;
T_1 V_22 = 0 , V_19 ;
if ( ! V_25 )
return;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
if ( V_20 )
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_1 , V_20 ) ;
if ( ! F_8 ( V_22 >= V_19 ) ) {
va_start ( args , V_26 ) ;
V_22 += F_16 ( V_18 + V_22 , V_19 - V_22 , V_26 , args ) ;
va_end ( args ) ;
}
F_17 ( V_23 , & V_25 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
}
void F_18 ( const char * V_23 , const struct V_13 * V_14 ,
const char * V_26 , ... )
{
T_2 args ;
char * V_18 ;
T_1 V_22 = 0 , V_19 ;
if ( ! V_14 || ! V_14 -> V_28 )
return;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
V_22 = F_13 ( V_18 , V_19 , F_12 ( V_14 ) ,
V_14 -> V_15 -> V_21 ) ;
if ( V_22 < V_19 ) {
va_start ( args , V_26 ) ;
V_22 += F_16 ( V_18 + V_22 , V_19 - V_22 , V_26 , args ) ;
va_end ( args ) ;
}
F_17 ( V_23 , & V_14 -> V_29 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
}
static T_1 F_19 ( char * V_5 , T_1 V_30 ,
const unsigned char * V_31 )
{
int V_32 , V_33 ;
const char * V_34 = NULL , * V_35 = NULL ;
T_1 V_22 ;
V_33 = V_31 [ 0 ] ;
if ( V_33 == V_36 ) {
int V_1 = F_20 ( V_31 ) ;
if ( V_1 < 10 ) {
V_22 = F_14 ( V_5 , V_30 ,
L_4 ,
V_1 ) ;
return V_22 ;
}
V_32 = ( V_31 [ 8 ] << 8 ) + V_31 [ 9 ] ;
} else
V_32 = V_31 [ 1 ] & 0x1f ;
if ( ! F_21 ( V_33 , V_32 , & V_34 , & V_35 ) ) {
if ( V_34 )
V_22 = F_14 ( V_5 , V_30 , L_3 , V_34 ) ;
else {
V_22 = F_14 ( V_5 , V_30 , L_5 , V_33 ) ;
if ( F_8 ( V_22 >= V_30 ) )
return V_22 ;
if ( V_33 >= V_37 )
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_6 ) ;
else if ( V_33 >= 0x60 && V_33 < 0x7e )
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_7 ) ;
}
} else {
if ( V_35 )
V_22 = F_14 ( V_5 , V_30 , L_3 , V_35 ) ;
else if ( V_34 )
V_22 = F_14 ( V_5 , V_30 , L_8 ,
V_34 , V_32 ) ;
else
V_22 = F_14 ( V_5 , V_30 ,
L_9 , V_33 , V_32 ) ;
}
F_8 ( V_22 >= V_30 ) ;
return V_22 ;
}
T_1 F_22 ( char * V_18 , T_1 V_19 ,
const unsigned char * V_38 , T_1 V_39 )
{
int V_1 , V_40 ;
T_1 V_22 ;
V_22 = F_19 ( V_18 , V_19 , V_38 ) ;
if ( V_22 >= V_19 )
return V_22 ;
V_1 = F_23 ( V_38 ) ;
if ( V_39 < V_1 )
V_1 = V_39 ;
for ( V_40 = 0 ; V_40 < V_1 ; ++ V_40 ) {
if ( V_22 > V_19 - 3 )
break;
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_10 , V_38 [ V_40 ] ) ;
}
return V_22 ;
}
void F_24 ( struct V_13 * V_41 )
{
int V_40 ;
char * V_18 ;
T_1 V_22 , V_19 ;
if ( ! V_41 -> V_28 )
return;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
V_22 = F_13 ( V_18 , V_19 ,
F_12 ( V_41 ) , V_41 -> V_15 -> V_21 ) ;
if ( V_22 >= V_19 )
goto V_42;
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 , L_11 ) ;
if ( F_8 ( V_22 >= V_19 ) )
goto V_42;
V_22 += F_19 ( V_18 + V_22 , V_19 - V_22 ,
V_41 -> V_28 ) ;
if ( V_22 >= V_19 )
goto V_42;
if ( V_41 -> V_43 > 16 ) {
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 , L_12 ) ;
F_17 ( V_44 , & V_41 -> V_29 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
for ( V_40 = 0 ; V_40 < V_41 -> V_43 ; V_40 += 16 ) {
T_1 V_45 = F_25 ( V_41 -> V_43 - V_40 , 16 ) ;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
break;
V_22 = F_13 ( V_18 , V_19 ,
F_12 ( V_41 ) ,
V_41 -> V_15 -> V_21 ) ;
if ( ! F_8 ( V_22 > V_19 - 58 ) ) {
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_13 , V_40 ) ;
F_26 ( & V_41 -> V_28 [ V_40 ] , V_45 ,
16 , 1 , V_18 + V_22 ,
V_19 - V_22 , false ) ;
}
F_17 ( V_44 , & V_41 -> V_29 -> V_27 , L_3 ,
V_18 ) ;
F_10 ( V_18 ) ;
}
return;
}
if ( ! F_8 ( V_22 > V_19 - 49 ) ) {
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 , L_14 ) ;
F_26 ( V_41 -> V_28 , V_41 -> V_43 , 16 , 1 ,
V_18 + V_22 , V_19 - V_22 ,
false ) ;
}
V_42:
F_17 ( V_44 , & V_41 -> V_29 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
}
static T_1
F_27 ( char * V_5 , T_1 V_30 ,
unsigned char V_46 , unsigned char V_47 )
{
T_1 V_22 = 0 ;
const char * V_48 = NULL ;
const char * V_49 = F_28 ( V_46 , V_47 ,
& V_48 ) ;
if ( V_49 ) {
V_22 = F_14 ( V_5 , V_30 , L_15 ,
V_49 ) ;
if ( V_48 )
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_16 , V_48 , V_47 ) ;
} else {
if ( V_46 >= 0x80 )
V_22 = F_14 ( V_5 , V_30 , L_17 ) ;
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_18 , V_46 ) ;
if ( V_47 >= 0x80 )
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_17 ) ;
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_19 , V_47 ) ;
}
return V_22 ;
}
static T_1
F_29 ( char * V_5 , T_1 V_30 ,
const struct V_50 * V_51 )
{
const char * V_52 ;
T_1 V_22 ;
V_22 = F_14 ( V_5 , V_30 , L_20 ) ;
V_52 = F_30 ( V_51 -> V_53 ) ;
if ( V_52 )
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_21 , V_52 ) ;
else
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
L_22 , V_51 -> V_53 ) ;
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 ,
F_31 ( V_51 ) ? L_23 : L_24 ) ;
if ( V_51 -> V_54 >= 0x72 )
V_22 += F_14 ( V_5 + V_22 , V_30 - V_22 , L_25 ) ;
return V_22 ;
}
static void
F_32 ( const struct V_24 * V_25 , const char * V_20 , int V_21 ,
const unsigned char * V_55 , int V_56 )
{
char * V_18 ;
T_1 V_19 ;
int V_57 ;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 += 16 ) {
int V_1 = F_25 ( V_56 - V_57 , 16 ) ;
T_1 V_22 ;
V_22 = F_13 ( V_18 , V_19 ,
V_20 , V_21 ) ;
F_26 ( & V_55 [ V_57 ] , V_1 , 16 , 1 ,
V_18 + V_22 , V_19 - V_22 ,
false ) ;
F_17 ( V_44 , & V_25 -> V_27 , L_3 , V_18 ) ;
}
F_10 ( V_18 ) ;
}
static void
F_33 ( const struct V_24 * V_25 , const char * V_20 ,
int V_21 , const struct V_50 * V_51 )
{
char * V_18 ;
T_1 V_22 , V_19 ;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
V_22 = F_13 ( V_18 , V_19 , V_20 , V_21 ) ;
V_22 += F_29 ( V_18 + V_22 , V_19 - V_22 , V_51 ) ;
F_17 ( V_44 , & V_25 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
V_22 = F_13 ( V_18 , V_19 , V_20 , V_21 ) ;
V_22 += F_27 ( V_18 + V_22 , V_19 - V_22 ,
V_51 -> V_46 , V_51 -> V_47 ) ;
F_17 ( V_44 , & V_25 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
}
static void
F_34 ( const struct V_24 * V_25 , const char * V_20 , int V_21 ,
const unsigned char * V_55 , int V_56 )
{
struct V_50 V_51 ;
if ( F_35 ( V_55 , V_56 , & V_51 ) )
F_33 ( V_25 , V_20 , V_21 , & V_51 ) ;
else
F_32 ( V_25 , V_20 , V_21 , V_55 , V_56 ) ;
}
void
F_36 ( const struct V_24 * V_25 , const char * V_20 ,
const struct V_50 * V_51 )
{
F_33 ( V_25 , V_20 , - 1 , V_51 ) ;
}
void F_37 ( const struct V_24 * V_25 , const char * V_20 ,
const unsigned char * V_55 , int V_56 )
{
F_34 ( V_25 , V_20 , - 1 , V_55 , V_56 ) ;
}
void F_38 ( const struct V_13 * V_41 )
{
F_34 ( V_41 -> V_29 , F_12 ( V_41 ) , V_41 -> V_15 -> V_21 ,
V_41 -> V_55 , V_58 ) ;
}
void F_39 ( const struct V_13 * V_41 , const char * V_59 ,
int V_60 )
{
char * V_18 ;
T_1 V_22 , V_19 ;
const char * V_61 = F_40 ( V_60 ) ;
const char * V_62 = F_41 ( V_41 -> V_63 ) ;
const char * V_64 = F_42 ( V_41 -> V_63 ) ;
V_18 = F_1 ( & V_19 ) ;
if ( ! V_18 )
return;
V_22 = F_13 ( V_18 , V_19 ,
F_12 ( V_41 ) , V_41 -> V_15 -> V_21 ) ;
if ( V_22 >= V_19 )
goto V_42;
if ( V_59 ) {
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_26 , V_59 ) ;
if ( F_8 ( V_22 >= V_19 ) )
goto V_42;
}
if ( V_61 )
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_21 , V_61 ) ;
else
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_27 , V_60 ) ;
if ( F_8 ( V_22 >= V_19 ) )
goto V_42;
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 , L_28 ) ;
if ( F_8 ( V_22 >= V_19 ) )
goto V_42;
if ( V_62 )
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_29 , V_62 ) ;
else
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_30 , F_43 ( V_41 -> V_63 ) ) ;
if ( F_8 ( V_22 >= V_19 ) )
goto V_42;
if ( V_64 )
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_31 , V_64 ) ;
else
V_22 += F_14 ( V_18 + V_22 , V_19 - V_22 ,
L_32 , F_44 ( V_41 -> V_63 ) ) ;
V_42:
F_17 ( V_44 , & V_41 -> V_29 -> V_27 , L_3 , V_18 ) ;
F_10 ( V_18 ) ;
}
