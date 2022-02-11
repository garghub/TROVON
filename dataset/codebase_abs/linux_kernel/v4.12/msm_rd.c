static void F_1 ( struct V_1 * V_2 , const void * V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
const char * V_7 = V_3 ;
while ( V_4 > 0 ) {
char * V_8 = & V_6 -> V_3 [ V_6 -> V_9 ] ;
int V_10 ;
F_2 ( V_2 -> V_11 , F_3 ( & V_2 -> V_6 ) > 0 ) ;
V_10 = F_4 ( V_4 , F_5 ( & V_2 -> V_6 ) ) ;
memcpy ( V_8 , V_7 , V_10 ) ;
V_6 -> V_9 = ( V_6 -> V_9 + V_10 ) & ( V_12 - 1 ) ;
V_4 -= V_10 ;
V_7 += V_10 ;
F_6 ( & V_2 -> V_11 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
enum V_13 type , const void * V_3 , int V_4 )
{
F_1 ( V_2 , & type , 4 ) ;
F_1 ( V_2 , & V_4 , 4 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
static T_1 F_8 ( struct V_14 * V_14 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_15 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
const char * V_8 = & V_6 -> V_3 [ V_6 -> V_17 ] ;
int V_10 = 0 , V_18 = 0 ;
F_9 ( & V_2 -> V_19 ) ;
V_18 = F_10 ( V_2 -> V_11 ,
F_11 ( & V_2 -> V_6 ) > 0 ) ;
if ( V_18 )
goto V_20;
V_10 = F_12 ( int , V_4 , F_13 ( & V_2 -> V_6 ) ) ;
if ( F_14 ( V_3 , V_8 , V_10 ) ) {
V_18 = - V_21 ;
goto V_20;
}
V_6 -> V_17 = ( V_6 -> V_17 + V_10 ) & ( V_12 - 1 ) ;
* V_15 += V_10 ;
F_6 ( & V_2 -> V_11 ) ;
V_20:
F_15 ( & V_2 -> V_19 ) ;
if ( V_18 )
return V_18 ;
return V_10 ;
}
static int F_16 ( struct V_22 * V_22 , struct V_14 * V_14 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
T_5 V_31 ;
T_6 V_32 ;
int V_18 = 0 ;
F_9 ( & V_25 -> V_33 ) ;
if ( V_2 -> V_34 || ! V_30 ) {
V_18 = - V_35 ;
goto V_20;
}
V_14 -> V_16 = V_2 ;
V_2 -> V_34 = true ;
V_30 -> V_36 -> V_37 ( V_30 , V_38 , & V_31 ) ;
V_32 = V_31 ;
F_7 ( V_2 , V_39 , & V_32 , sizeof( V_32 ) ) ;
V_20:
F_15 ( & V_25 -> V_33 ) ;
return V_18 ;
}
static int F_17 ( struct V_22 * V_22 , struct V_14 * V_14 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
V_2 -> V_34 = false ;
return 0 ;
}
int F_18 ( struct V_40 * V_41 )
{
struct V_26 * V_27 = V_41 -> V_25 -> V_28 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
if ( V_27 -> V_2 )
return 0 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_25 = V_41 -> V_25 ;
V_2 -> V_6 . V_3 = V_2 -> V_3 ;
F_20 ( & V_2 -> V_19 ) ;
V_27 -> V_2 = V_2 ;
F_21 ( & V_2 -> V_11 ) ;
V_43 = F_22 ( L_1 , V_46 | V_47 ,
V_41 -> V_48 , V_2 , & V_49 ) ;
if ( ! V_43 ) {
F_23 ( L_2 ,
V_41 -> V_48 ) ;
goto V_50;
}
return 0 ;
V_50:
F_24 ( V_27 ) ;
return - 1 ;
}
void F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
if ( ! V_2 )
return;
V_27 -> V_2 = NULL ;
F_25 ( & V_2 -> V_19 ) ;
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_51 * V_52 , int V_53 ,
T_5 V_54 , T_6 V_55 )
{
struct V_56 * V_57 = V_52 -> V_58 [ V_53 ] . V_57 ;
const char * V_3 ;
V_3 = F_28 ( & V_57 -> V_59 ) ;
if ( F_29 ( V_3 ) )
return;
if ( V_54 ) {
V_3 += V_54 - V_52 -> V_58 [ V_53 ] . V_54 ;
} else {
V_54 = V_52 -> V_58 [ V_53 ] . V_54 ;
V_55 = V_57 -> V_59 . V_55 ;
}
F_7 (rd, RD_GPUADDR,
(uint32_t[3]){ iova, size, iova >> 32 }, 12 ) ;
F_7 ( V_2 , V_60 , V_3 , V_55 ) ;
F_30 ( & V_57 -> V_59 ) ;
}
void F_31 ( struct V_51 * V_52 )
{
struct V_24 * V_25 = V_52 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_2 = V_27 -> V_2 ;
char V_61 [ 128 ] ;
int V_62 , V_10 ;
if ( ! V_2 -> V_34 )
return;
F_32 ( ! F_33 ( & V_25 -> V_33 ) ) ;
V_10 = snprintf ( V_61 , sizeof( V_61 ) , L_3 ,
V_63 , V_64 -> V_65 , F_34 ( V_64 ) ,
V_52 -> V_66 -> V_67 ) ;
F_7 ( V_2 , V_68 , V_61 , F_35 ( V_10 , 4 ) ) ;
if ( V_69 ) {
for ( V_62 = 0 ; V_62 < V_52 -> V_70 ; V_62 ++ ) {
if ( V_52 -> V_58 [ V_62 ] . V_71 & V_72 )
continue;
F_27 ( V_2 , V_52 , V_62 , 0 , 0 ) ;
}
}
for ( V_62 = 0 ; V_62 < V_52 -> V_73 ; V_62 ++ ) {
T_5 V_54 = V_52 -> V_74 [ V_62 ] . V_54 ;
T_6 V_75 = V_52 -> V_74 [ V_62 ] . V_55 ;
if ( ! V_69 ) {
F_27 ( V_2 , V_52 , V_52 -> V_74 [ V_62 ] . V_53 ,
V_52 -> V_74 [ V_62 ] . V_54 , V_75 * 4 ) ;
}
switch ( V_52 -> V_74 [ V_62 ] . type ) {
case V_76 :
break;
case V_77 :
case V_78 :
F_7 (rd, RD_CMDSTREAM_ADDR,
(uint32_t[3]){ iova, szd, iova >> 32 }, 12 ) ;
break;
}
}
}
