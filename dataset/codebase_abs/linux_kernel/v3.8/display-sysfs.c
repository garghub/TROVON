static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_8 = V_7 -> V_9 != V_10 ;
return snprintf ( V_5 , V_11 , L_1 , V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
bool V_8 ;
V_13 = F_4 ( V_5 , & V_8 ) ;
if ( V_13 )
return V_13 ;
if ( V_8 != ( V_7 -> V_9 != V_10 ) ) {
if ( V_8 ) {
V_13 = V_7 -> V_14 -> V_15 ( V_7 ) ;
if ( V_13 )
return V_13 ;
} else {
V_7 -> V_14 -> V_16 ( V_7 ) ;
}
}
return V_12 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_11 , L_1 ,
V_7 -> V_14 -> V_17 ?
V_7 -> V_14 -> V_17 ( V_7 ) : 0 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
bool V_18 ;
if ( ! V_7 -> V_14 -> V_19 || ! V_7 -> V_14 -> V_17 )
return - V_20 ;
V_13 = F_4 ( V_5 , & V_18 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_19 ( V_7 , V_18 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 V_22 ;
if ( ! V_7 -> V_14 -> V_23 )
return - V_20 ;
V_7 -> V_14 -> V_23 ( V_7 , & V_22 ) ;
return snprintf ( V_5 , V_11 , L_2 ,
V_22 . V_24 ,
V_22 . V_25 , V_22 . V_26 , V_22 . V_27 , V_22 . V_28 ,
V_22 . V_29 , V_22 . V_30 , V_22 . V_31 , V_22 . V_32 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 V_22 = V_7 -> V_33 . V_34 ;
int V_13 , V_35 ;
if ( ! V_7 -> V_14 -> V_36 || ! V_7 -> V_14 -> V_37 )
return - V_20 ;
V_35 = 0 ;
#ifdef F_9
if ( strncmp ( L_3 , V_5 , 3 ) == 0 ) {
V_22 = V_38 ;
V_35 = 1 ;
} else if ( strncmp ( L_4 , V_5 , 4 ) == 0 ) {
V_22 = V_39 ;
V_35 = 1 ;
}
#endif
if ( ! V_35 && sscanf ( V_5 , L_5 ,
& V_22 . V_24 ,
& V_22 . V_25 , & V_22 . V_26 , & V_22 . V_27 , & V_22 . V_28 ,
& V_22 . V_29 , & V_22 . V_30 , & V_22 . V_31 , & V_22 . V_32 ) != 9 )
return - V_40 ;
V_13 = V_7 -> V_14 -> V_37 ( V_7 , & V_22 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_14 -> V_16 ( V_7 ) ;
V_7 -> V_14 -> V_36 ( V_7 , & V_22 ) ;
V_13 = V_7 -> V_14 -> V_15 ( V_7 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_41 ;
if ( ! V_7 -> V_14 -> V_42 )
return - V_20 ;
V_41 = V_7 -> V_14 -> V_42 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_41 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_43 , V_13 ;
if ( ! V_7 -> V_14 -> V_44 || ! V_7 -> V_14 -> V_42 )
return - V_20 ;
V_13 = F_12 ( V_5 , 0 , & V_43 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_44 ( V_7 , V_43 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_45 ;
if ( ! V_7 -> V_14 -> V_46 )
return - V_20 ;
V_45 = V_7 -> V_14 -> V_46 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_45 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
bool V_45 ;
if ( ! V_7 -> V_14 -> V_47 || ! V_7 -> V_14 -> V_46 )
return - V_20 ;
V_13 = F_4 ( V_5 , & V_45 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_47 ( V_7 , V_45 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_48 ;
if ( ! V_7 -> V_14 -> V_49 )
return - V_20 ;
V_48 = V_7 -> V_14 -> V_49 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_7 , V_48 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_48 ;
int V_13 ;
if ( ! V_7 -> V_14 -> V_49 || ! V_7 -> V_14 -> V_50 )
return - V_20 ;
V_13 = F_17 ( V_5 , 0 , & V_48 ) ;
if ( V_13 )
return V_13 ;
if ( V_48 > 0xfffff )
return - V_40 ;
V_13 = V_7 -> V_14 -> V_50 ( V_7 , V_48 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
int F_18 ( struct V_51 * V_52 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_53 , V_13 ;
V_53 = 0 ;
while ( ( V_4 = V_54 [ V_53 ++ ] ) != NULL ) {
V_13 = F_19 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 ) {
for ( V_53 = V_53 - 2 ; V_53 >= 0 ; V_53 -- ) {
V_4 = V_54 [ V_53 ] ;
F_20 ( & V_7 -> V_2 , V_4 ) ;
}
F_21 ( L_8 ) ;
return V_13 ;
}
}
V_13 = F_22 ( & V_52 -> V_2 . V_55 , & V_7 -> V_2 . V_55 ,
F_23 ( & V_7 -> V_2 ) ) ;
if ( V_13 ) {
while ( ( V_4 = V_54 [ V_53 ++ ] ) != NULL )
F_20 ( & V_7 -> V_2 , V_4 ) ;
F_21 ( L_9 ) ;
return V_13 ;
}
return 0 ;
}
void F_24 ( struct V_51 * V_52 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_53 = 0 ;
F_25 ( & V_52 -> V_2 . V_55 , F_23 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_54 [ V_53 ++ ] ) != NULL )
F_20 ( & V_7 -> V_2 , V_4 ) ;
}
