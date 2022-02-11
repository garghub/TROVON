static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 V_4 , T_1 V_5 )
{
switch ( V_6 ) {
case V_7 :
if ( V_5 > V_4 )
return 1 ;
return 0 ;
case V_8 :
if ( ( V_2 -> V_9 == V_10 ) && ( V_5 > V_4 ) )
return 1 ;
if ( ( V_3 -> V_9 != V_10 ) && ( V_5 > V_4 ) )
return 1 ;
if ( ( V_2 -> V_9 == V_10 ) && ( V_5 > ( V_4 * V_11 / 100 ) ) )
return 1 ;
if ( ( V_5 * V_11 / 100 ) > V_4 )
return 1 ;
return 0 ;
}
return 0 ;
}
static int F_2 ( T_2 V_9 , unsigned char * V_12 ,
unsigned char * * V_13 , T_3 * V_14 , T_3 * V_15 )
{
struct V_1 * V_2 ;
int V_16 , V_17 = V_18 ;
T_1 V_19 , V_20 ;
char * V_21 ;
V_21 = F_3 ( * V_15 , V_22 ) ;
if ( ! V_21 ) {
F_4 ( L_1 ) ;
return V_17 ;
}
V_19 = * V_14 ;
V_20 = * V_15 ;
F_5 ( & V_23 ) ;
F_6 (this, &jffs2_compressor_list, list) {
if ( ! V_2 -> V_24 || V_2 -> V_25 )
continue;
if ( V_9 && ( V_9 != V_2 -> V_9 ) )
continue;
V_2 -> V_26 ++ ;
F_7 ( & V_23 ) ;
* V_14 = V_19 ;
* V_15 = V_20 ;
V_16 = V_2 -> V_24 ( V_12 , V_21 , V_14 , V_15 ) ;
F_5 ( & V_23 ) ;
V_2 -> V_26 -- ;
if ( ! V_16 ) {
V_17 = V_2 -> V_9 ;
V_2 -> V_27 ++ ;
V_2 -> V_28 += * V_14 ;
V_2 -> V_29 += * V_15 ;
break;
}
}
F_7 ( & V_23 ) ;
if ( V_17 == V_18 )
F_8 ( V_21 ) ;
else
* V_13 = V_21 ;
return V_17 ;
}
T_4 F_9 ( struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned char * V_12 , unsigned char * * V_13 ,
T_1 * V_14 , T_1 * V_15 )
{
int V_17 = V_18 ;
int V_34 , V_35 ;
struct V_1 * V_2 , * V_3 = NULL ;
unsigned char * V_21 = NULL , * V_36 ;
T_1 V_19 , V_20 ;
T_1 V_37 = 0 , V_38 = 0 ;
if ( V_31 -> V_39 . V_40 )
V_34 = V_31 -> V_39 . V_9 ;
else
V_34 = V_6 ;
switch ( V_34 ) {
case V_41 :
break;
case V_42 :
V_17 = F_2 ( 0 , V_12 , V_13 , V_14 ,
V_15 ) ;
break;
case V_7 :
case V_8 :
V_19 = * V_14 ;
V_20 = * V_15 ;
F_5 ( & V_23 ) ;
F_6 (this, &jffs2_compressor_list, list) {
if ( ( ! V_2 -> V_24 ) || ( V_2 -> V_25 ) )
continue;
if ( ( V_2 -> V_43 < V_19 ) && ( V_2 -> V_44 ) ) {
F_7 ( & V_23 ) ;
F_8 ( V_2 -> V_44 ) ;
F_5 ( & V_23 ) ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = NULL ;
}
if ( ! V_2 -> V_44 ) {
F_7 ( & V_23 ) ;
V_36 = F_3 ( V_19 , V_22 ) ;
F_5 ( & V_23 ) ;
if ( ! V_36 ) {
F_4 ( L_2 ,
V_19 ) ;
continue;
}
else {
V_2 -> V_44 = V_36 ;
V_2 -> V_43 = V_19 ;
}
}
V_2 -> V_26 ++ ;
F_7 ( & V_23 ) ;
* V_14 = V_19 ;
* V_15 = V_20 ;
V_35 = V_2 -> V_24 ( V_12 , V_2 -> V_44 , V_14 , V_15 ) ;
F_5 ( & V_23 ) ;
V_2 -> V_26 -- ;
if ( ! V_35 ) {
if ( ( ( ! V_38 ) || F_1 ( V_2 , V_3 , * V_15 , V_38 ) )
&& ( * V_15 < * V_14 ) ) {
V_38 = * V_15 ;
V_37 = * V_14 ;
V_3 = V_2 ;
}
}
}
if ( V_38 ) {
* V_15 = V_38 ;
* V_14 = V_37 ;
V_21 = V_3 -> V_44 ;
V_3 -> V_44 = NULL ;
V_3 -> V_43 = 0 ;
V_3 -> V_27 ++ ;
V_3 -> V_28 += V_37 ;
V_3 -> V_29 += V_38 ;
V_17 = V_3 -> V_9 ;
* V_13 = V_21 ;
}
F_7 ( & V_23 ) ;
break;
case V_45 :
V_17 = F_2 ( V_10 , V_12 ,
V_13 , V_14 , V_15 ) ;
break;
case V_46 :
V_17 = F_2 ( V_47 , V_12 ,
V_13 , V_14 , V_15 ) ;
break;
default:
F_10 ( L_3 ) ;
}
if ( V_17 == V_18 ) {
* V_13 = V_12 ;
* V_14 = * V_15 ;
V_48 ++ ;
V_49 += * V_14 ;
}
return V_17 ;
}
int F_11 ( struct V_30 * V_31 , struct V_32 * V_33 ,
T_4 V_50 , unsigned char * V_51 ,
unsigned char * V_52 , T_1 V_15 , T_1 V_14 )
{
struct V_1 * V_2 ;
int V_17 ;
if ( ( V_50 & 0xff ) <= V_47 )
V_50 &= 0xff ;
switch ( V_50 & 0xff ) {
case V_18 :
memcpy ( V_52 , V_51 , V_14 ) ;
V_53 ++ ;
break;
case V_54 :
memset ( V_52 , 0 , V_14 ) ;
break;
default:
F_5 ( & V_23 ) ;
F_6 (this, &jffs2_compressor_list, list) {
if ( V_50 == V_2 -> V_9 ) {
V_2 -> V_26 ++ ;
F_7 ( & V_23 ) ;
V_17 = V_2 -> V_55 ( V_51 , V_52 , V_15 , V_14 ) ;
F_5 ( & V_23 ) ;
if ( V_17 ) {
F_4 ( L_4 ,
V_2 -> V_56 , V_17 ) ;
}
else {
V_2 -> V_57 ++ ;
}
V_2 -> V_26 -- ;
F_7 ( & V_23 ) ;
return V_17 ;
}
}
F_4 ( L_5 , V_50 ) ;
F_7 ( & V_23 ) ;
return - V_58 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_59 )
{
struct V_1 * V_2 ;
if ( ! V_59 -> V_56 ) {
F_4 ( L_6 ) ;
return - 1 ;
}
V_59 -> V_43 = 0 ;
V_59 -> V_44 = NULL ;
V_59 -> V_26 = 0 ;
V_59 -> V_28 = 0 ;
V_59 -> V_29 = 0 ;
V_59 -> V_27 = 0 ;
V_59 -> V_57 = 0 ;
F_13 ( 1 , L_7 , V_59 -> V_56 ) ;
F_5 ( & V_23 ) ;
F_6 (this, &jffs2_compressor_list, list) {
if ( V_2 -> V_60 < V_59 -> V_60 ) {
F_14 ( & V_59 -> V_61 , V_2 -> V_61 . V_62 ) ;
goto V_63;
}
}
F_15 ( & V_59 -> V_61 , & V_64 ) ;
V_63:
F_16 (list_for_each_entry(this, &jffs2_compressor_list, list) {
printk(KERN_DEBUG L_8, this->name, this->priority);
})
F_7 ( & V_23 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_59 )
{
F_16 ( struct V_1 * V_2 ) ;
F_13 ( 1 , L_9 , V_59 -> V_56 ) ;
F_5 ( & V_23 ) ;
if ( V_59 -> V_26 ) {
F_7 ( & V_23 ) ;
F_4 ( L_10 ) ;
return - 1 ;
}
F_18 ( & V_59 -> V_61 ) ;
F_16 (list_for_each_entry(this, &jffs2_compressor_list, list) {
printk(KERN_DEBUG L_8, this->name, this->priority);
})
F_7 ( & V_23 ) ;
return 0 ;
}
void F_19 ( unsigned char * V_65 , unsigned char * V_66 )
{
if ( V_66 != V_65 )
F_8 ( V_65 ) ;
}
int T_5 F_20 ( void )
{
#ifdef F_21
F_22 () ;
#endif
#ifdef F_23
F_24 () ;
#endif
#ifdef F_25
F_26 () ;
F_27 () ;
#endif
#ifdef F_28
F_29 () ;
#endif
#ifdef F_30
V_6 = V_41 ;
F_13 ( 1 , L_11 ) ;
#else
#ifdef F_31
V_6 = V_7 ;
F_13 ( 1 , L_12 ) ;
#else
#ifdef F_32
V_6 = V_8 ;
F_13 ( 1 , L_13 ) ;
#else
F_13 ( 1 , L_14 ) ;
#endif
#endif
#endif
return 0 ;
}
int F_33 ( void )
{
#ifdef F_28
F_34 () ;
#endif
#ifdef F_25
F_35 () ;
F_36 () ;
#endif
#ifdef F_23
F_37 () ;
#endif
#ifdef F_21
F_38 () ;
#endif
return 0 ;
}
