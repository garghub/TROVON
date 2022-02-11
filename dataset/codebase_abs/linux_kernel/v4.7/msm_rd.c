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
V_18 = F_14 ( V_3 , V_8 , V_10 ) ;
if ( V_18 )
goto V_20;
V_6 -> V_17 = ( V_6 -> V_17 + V_10 ) & ( V_12 - 1 ) ;
* V_15 += V_10 ;
F_6 ( & V_2 -> V_11 ) ;
V_20:
F_15 ( & V_2 -> V_19 ) ;
if ( V_18 )
return V_18 ;
return V_10 ;
}
static int F_16 ( struct V_21 * V_21 , struct V_14 * V_14 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_29 = V_26 -> V_29 ;
T_5 V_30 ;
T_6 V_31 ;
int V_18 = 0 ;
F_9 ( & V_24 -> V_32 ) ;
if ( V_2 -> V_33 || ! V_29 ) {
V_18 = - V_34 ;
goto V_20;
}
V_14 -> V_16 = V_2 ;
V_2 -> V_33 = true ;
V_29 -> V_35 -> V_36 ( V_29 , V_37 , & V_30 ) ;
V_31 = V_30 ;
F_7 ( V_2 , V_38 , & V_31 , sizeof( V_31 ) ) ;
V_20:
F_15 ( & V_24 -> V_32 ) ;
return V_18 ;
}
static int F_17 ( struct V_21 * V_21 , struct V_14 * V_14 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
V_2 -> V_33 = false ;
return 0 ;
}
int F_18 ( struct V_39 * V_40 )
{
struct V_25 * V_26 = V_40 -> V_24 -> V_27 ;
struct V_1 * V_2 ;
if ( V_26 -> V_2 )
return 0 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_24 = V_40 -> V_24 ;
V_2 -> V_6 . V_3 = V_2 -> V_3 ;
F_20 ( & V_2 -> V_19 ) ;
V_26 -> V_2 = V_2 ;
F_21 ( & V_2 -> V_11 ) ;
V_2 -> V_43 = F_19 ( sizeof( * V_2 -> V_43 ) , V_41 ) ;
if ( ! V_2 -> V_43 )
goto V_44;
V_2 -> V_45 = F_22 ( L_1 , V_46 | V_47 ,
V_40 -> V_48 , V_2 , & V_49 ) ;
if ( ! V_2 -> V_45 ) {
F_23 ( L_2 ,
V_40 -> V_48 -> V_50 . V_51 ) ;
goto V_44;
}
V_2 -> V_43 -> V_40 = V_40 ;
V_2 -> V_43 -> V_52 = V_2 -> V_45 ;
V_2 -> V_43 -> V_53 = NULL ;
F_9 ( & V_40 -> V_54 ) ;
F_24 ( & V_2 -> V_43 -> V_55 , & V_40 -> V_56 ) ;
F_15 ( & V_40 -> V_54 ) ;
return 0 ;
V_44:
F_25 ( V_40 ) ;
return - 1 ;
}
void F_25 ( struct V_39 * V_40 )
{
struct V_25 * V_26 = V_40 -> V_24 -> V_27 ;
struct V_1 * V_2 = V_26 -> V_2 ;
if ( ! V_2 )
return;
V_26 -> V_2 = NULL ;
F_26 ( V_2 -> V_45 ) ;
if ( V_2 -> V_43 ) {
F_9 ( & V_40 -> V_54 ) ;
F_27 ( & V_2 -> V_43 -> V_55 ) ;
F_15 ( & V_40 -> V_54 ) ;
F_28 ( V_2 -> V_43 ) ;
}
F_29 ( & V_2 -> V_19 ) ;
F_28 ( V_2 ) ;
}
void F_30 ( struct V_57 * V_58 )
{
struct V_23 * V_24 = V_58 -> V_24 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_2 = V_26 -> V_2 ;
char V_59 [ 128 ] ;
int V_60 , V_10 ;
if ( ! V_2 -> V_33 )
return;
F_31 ( ! F_32 ( & V_24 -> V_32 ) ) ;
V_10 = snprintf ( V_59 , sizeof( V_59 ) , L_3 ,
V_61 , V_62 -> V_63 , F_33 ( V_62 ) ,
V_58 -> V_64 -> V_65 ) ;
F_7 ( V_2 , V_66 , V_59 , F_34 ( V_10 , 4 ) ) ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 ; V_60 ++ ) {
T_6 V_68 = V_58 -> V_69 [ V_60 ] . V_68 ;
T_6 V_70 = V_58 -> V_69 [ V_60 ] . V_70 ;
T_6 V_71 = V_58 -> V_69 [ V_60 ] . V_72 ;
struct V_73 * V_74 = V_58 -> V_75 [ V_68 ] . V_74 ;
const char * V_3 = F_35 ( & V_74 -> V_76 ) ;
if ( F_36 ( V_3 ) )
continue;
V_3 += V_70 - V_58 -> V_75 [ V_68 ] . V_70 ;
F_7 (rd, RD_GPUADDR,
(uint32_t[2]){ iova, szd * 4 }, 8 ) ;
F_7 ( V_2 , V_77 ,
V_3 , V_71 * 4 ) ;
switch ( V_58 -> V_69 [ V_60 ] . type ) {
case V_78 :
break;
case V_79 :
case V_80 :
F_7 (rd, RD_CMDSTREAM_ADDR,
(uint32_t[2]){ iova, szd }, 8 ) ;
break;
}
}
}
